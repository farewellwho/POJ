#include <stdio.h>

void reportTriplePeak(int p, int e, int i, int d, int k);

int main()
{
	int physicalPeak, emotionalPeak, intellectualPeak, day;
	int k = 1;
	while (scanf("%d%d%d%d", &physicalPeak, &emotionalPeak, &intellectualPeak, &day) && physicalPeak != -1)
	{
		reportTriplePeak(physicalPeak, emotionalPeak, intellectualPeak, day, k++); // 调用子程序计算 triple peak
	}
	return 0;
}
// 求 triple peak， p、e、i、d 分别不大于各自的周期。
// 基本思想是：把p、e、i想象成三个跑步选手，他们的起跑位置为各自的初始值，步长为各自的周期；以某一个初始的值（比如 d + 1）作为他们的目的地（destination）。
// 三个跑步选手开始跑步，依次等待三个选手都跑过目的地（假设他们当前的位置用pp、ee、ii表示，则三者都大于等于destination）；此时做判断，若pp == ee == ii，则
// 跑步结束，此时的 pp/ee/ii 就是triple peak，输出 pp - d；否则，更新destination为pp、ee、ii中的最大者，进行下一轮跑步。
void reportTriplePeak(int p, int e, int i, int d, int k)
{
	int physicalCycle, emotionalCycle, intellectualCycle;
	physicalCycle = 23;
	emotionalCycle = 28;
	intellectualCycle = 33;
	// 将 p、e、i 转换到各自周期以内
	if (p >= physicalCycle || e >= emotionalCycle || i >= intellectualCycle)
	{
		reportTriplePeak(p % physicalCycle, e % emotionalCycle, i % intellectualCycle, d, k);
	}
	else
	{
		int destination = d + 1; // 因为 d 当天不算，所以从d + 1开始
		int pp = p - physicalCycle;
		int ee = e - emotionalCycle;
		int ii = i - intellectualCycle;
		while (1)
		{
			//等待第一个选手跑过终点
			while (pp < destination)
			{
				pp += physicalCycle;
			}
			//等待第二个选手跑过终点
			while (ee < destination)
			{
				ee += emotionalCycle;
			}
			//等待第三个选手跑过终点
			while (ii < destination)
			{
				ii += intellectualCycle;
			}
			//判断和输出
			if (pp == ee && ee == ii)
			{
				printf("Case %d: the next triple peak occurs in %d days.\n", k, pp - d);
				break;
			}
			// 更新目的地，开始下一次跑步
			destination = pp > ee ? pp : ee;
			destination = destination > ii ? destination : ii;
		}
	}
}