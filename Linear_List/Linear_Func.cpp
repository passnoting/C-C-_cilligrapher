#define _CRT_SECURE_NO_WARNINGS

// Implementing a linear list

#include"Linear_Func.h"


// ��ʼ��˳���
void SL_Init(SL& ps)
{
	ps.a = NULL;
	ps.capacity = 0;
	ps.size = 0;
}

// �������
void Check_Capacity(SL& ps)
{
	if (ps.capacity == ps.size)
	{
		int newcapacity = ps.capacity == 0 ? 4 : ps.capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps.a, sizeof(SLDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("Check_Capacity realloc fail");
			return;
		}
		ps.a = tmp;
		ps.capacity = newcapacity;
	}
}

// ˳����п�
bool SL_Empty(SL& ps)
{
	return ps.size == 0 ? true : false;
}

// ��ӡ����
void SL_Print(SL& ps)
{
	int i = 0;
	cout << "˳������������£�=> " << endl;
	for (i = 0; i < ps.size; i++)
	{
		cout << ps.a[i] << " ";
	}
	cout << endl;
}


// ͷ������
void SL_Push_Front(SL& ps, SLDatatype x)
{
	// �������
	Check_Capacity(ps);

	// ��������
	int i = 0;
	for (i = ps.size - 1; i >= 0; i--)
	{
		ps.a[i+1] = ps.a[i];
	}
	ps.a[0] = x;

	// ++size
	++ps.size;
}

// β������
void SL_Push_Back(SL& ps, SLDatatype x)
{
	// �������
	Check_Capacity(ps);

	// ��������
	ps.a[ps.size] = x;

	// ++size
	++ps.size;
}

// ͷɾ����
void SL_Pop_Front(SL& ps)
{
	// �ж��Ƿ�Ϊ��
	assert(!SL_Empty(ps));

	// ɾ������
	int i = 0;
	for (i = 1; i < ps.size; i++)
	{
		ps.a[i-1] = ps.a[i];
	}

	// --size
	--ps.size;
}

// βɾ����
void SL_Pop_Back(SL& ps)
{
	// �ж��Ƿ�Ϊ��
	assert(!SL_Empty(ps));

	// ɾ������
	ps.size--;
}

// ��posλ�ò�������
void SL_Insert(SL& ps, int pos, SLDatatype x)
{
	// �������
	Check_Capacity(ps);

	// ��������
	int i = 0;
	for (i = ps.size - 1; i >= pos; i--)
	{
		ps.a[i+1] = ps.a[i];
	}
	ps.a[pos] = x;

	// ++size
	++ps.size;
}

// ɾ��posλ���ϵ�����
void SL_Erase(SL& ps, int pos)
{
	// �ж��Ƿ�Ϊ��
	assert(!SL_Empty(ps));

	// ɾ������
	int i = 0;
	for (i = pos + 1; i < ps.size; i++)
	{
		ps.a[i-1] = ps.a[i];
	}

	// --size
	ps.size--;
}

// ����ĳһ����	(�������±�)
int SL_Find(SL& ps, SLDatatype x)
{
	int i = 0;
	for (i = 0; i < ps.size; i++)
	{
		if (ps.a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// ����˳���
void SL_Destroy(SL& ps)
{
	free(ps.a);
	ps.capacity = ps.size = 0;
}