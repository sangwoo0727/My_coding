/* N���� ���� ���� �Ҽ��� ����� ã�� ���α׷�
N�� ������ 100�����̱� ������ 2���������� �����ϴٰ� ����
N�� arr�迭�� ���� �� �ݺ����� ���鼭, 1���� ������ �������� 0�϶� ī��Ʈ�� ������Ų��
ī��Ʈ�� 2�� ��쿡��(�Ҽ��� ���) cnt2�� �������� �Ҽ��� ������ ã�Ƴ´�
�ٸ� ��� Ǯ�� �߿����� 2���������� �ð��� ����Ǵ� �ڵ�� ��ã�Ҵ�.*/

#include <iostream>
using namespace std;

int arr[105];
int cnt1, cnt2;

int main() {
	int N;
	scanf("%d", &N); //100������ ����
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (arr[i] % j == 0)
				cnt1++;
		}
		if (cnt1 == 2)
			cnt2++;
		cnt1 = 0;
	}
	printf("%d\n", cnt2);
	return 0;
}