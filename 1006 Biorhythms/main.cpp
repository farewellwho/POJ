#include <stdio.h>

void reportTriplePeak(int p, int e, int i, int d, int k);

int main()
{
	int physicalPeak, emotionalPeak, intellectualPeak, day;
	int k = 1;
	while (scanf("%d%d%d%d", &physicalPeak, &emotionalPeak, &intellectualPeak, &day) && physicalPeak != -1)
	{
		reportTriplePeak(physicalPeak, emotionalPeak, intellectualPeak, day, k++); // �����ӳ������ triple peak
	}
	return 0;
}
// �� triple peak�� p��e��i��d �ֱ𲻴��ڸ��Ե����ڡ�
// ����˼���ǣ���p��e��i����������ܲ�ѡ�֣����ǵ�����λ��Ϊ���Եĳ�ʼֵ������Ϊ���Ե����ڣ���ĳһ����ʼ��ֵ������ d + 1����Ϊ���ǵ�Ŀ�ĵأ�destination����
// �����ܲ�ѡ�ֿ�ʼ�ܲ������εȴ�����ѡ�ֶ��ܹ�Ŀ�ĵأ��������ǵ�ǰ��λ����pp��ee��ii��ʾ�������߶����ڵ���destination������ʱ���жϣ���pp == ee == ii����
// �ܲ���������ʱ�� pp/ee/ii ����triple peak����� pp - d�����򣬸���destinationΪpp��ee��ii�е�����ߣ�������һ���ܲ���
void reportTriplePeak(int p, int e, int i, int d, int k)
{
	int physicalCycle, emotionalCycle, intellectualCycle;
	physicalCycle = 23;
	emotionalCycle = 28;
	intellectualCycle = 33;
	// �� p��e��i ת����������������
	if (p >= physicalCycle || e >= emotionalCycle || i >= intellectualCycle)
	{
		reportTriplePeak(p % physicalCycle, e % emotionalCycle, i % intellectualCycle, d, k);
	}
	else
	{
		int destination = d + 1; // ��Ϊ d ���첻�㣬���Դ�d + 1��ʼ
		int pp = p - physicalCycle;
		int ee = e - emotionalCycle;
		int ii = i - intellectualCycle;
		while (1)
		{
			//�ȴ���һ��ѡ���ܹ��յ�
			while (pp < destination)
			{
				pp += physicalCycle;
			}
			//�ȴ��ڶ���ѡ���ܹ��յ�
			while (ee < destination)
			{
				ee += emotionalCycle;
			}
			//�ȴ�������ѡ���ܹ��յ�
			while (ii < destination)
			{
				ii += intellectualCycle;
			}
			//�жϺ����
			if (pp == ee && ee == ii)
			{
				printf("Case %d: the next triple peak occurs in %d days.\n", k, pp - d);
				break;
			}
			// ����Ŀ�ĵأ���ʼ��һ���ܲ�
			destination = pp > ee ? pp : ee;
			destination = destination > ii ? destination : ii;
		}
	}
}