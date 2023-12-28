#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"

//����
static void CheckCapacity(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("CheckCapacity : %s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ�\n");
		}
	}
}

//����ͨѶ¼�����Ϣ
void LoadContact(Contact* pc)
{
	assert(pc);
	//���ļ�
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	//�����ļ���Ϣ
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	//�ر��ļ�
	fclose(pfRead);
	pfRead = NULL;
}


//��ʼ��ͨѶ¼
int ContactInit(Contact* pc)
{
	    assert(pc);
		pc->count = 0;
		pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
		if (pc->data == NULL)
		{
			printf("ContactInit : %s\n", strerror(errno));
			return 1;
		}
		pc->capacity = DEFAULT_SZ;
		//�����ļ���Ϣ��ͨѶ¼
		LoadContact(pc);
		return 0;
}


//����ͨѶ¼����
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	printf("��������>:");
	scanf("%s", pc->data[pc->count].name);
	printf("��������>:");
	scanf("%d", &pc->data[pc->count].age);
	printf("�����Ա�>:");
	scanf("%s", pc->data[pc->count].sex);
	printf("����绰>:");
	scanf("%s", pc->data[pc->count].tele);
	printf("�����ַ>:");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("���ӳɹ�\n");
}

//����
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//ɾ��ͨѶ¼������
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��,�޷�ɾ����Ϣ\n");
		return;
	}
	printf("������Ҫɾ�����˵�����\n");
	scanf("%s", name);
    
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}

//��ʾͨѶ¼�е���Ϣ
void ShowContact(Contact* pc)
{
	assert(pc);
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

//����ͨѶ¼�����Ϣ
void SearchContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("��������Ҫ���ҵ��˵�����:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("���Ҳ��ҵ��˵���Ϣ������\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-30s\n", pc->data[ret].name, pc->data[ret].age, pc->data[ret].sex, pc->data[ret].tele, pc->data[ret].addr);
}

//�޸�ͨѶ�����Ϣ
void ModifyContatct(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("��������Ҫ�޸ĵ��˵�����:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("��Ҫ�޸ĵ��˵���Ϣ������,�޷��޸�\n");
		return;
	}
	printf("�������޸ĺ������>:");
	scanf("%s", pc->data[ret].name);
	printf("�������޸ĺ������>:");
	scanf("%d", &pc->data[ret].age);
	printf("�������޸ĺ���Ա�>:");
	scanf("%s", pc->data[ret].sex);
	printf("�������޸ĺ�ĵ绰>:");
	scanf("%s", pc->data[ret].tele);
	printf("�������޸ĺ�ĵ�ַ>:");
	scanf("%s", pc->data[ret].addr);
	printf("�޸ĳɹ�\n");
}

//�����ֽ�������
static int NameByCmp(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

//�����ֶ�ͨѶ¼�����Ϣ��������
void QsortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), NameByCmp);
	printf("����ɹ�\n");
}

//����ͨѶ¼,�ͷ��ڴ�
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//����ͨѶ¼�е���Ϣ���ļ���
void SaveContact(const Contact* pc)
{
	assert(pc);
	//���ļ�
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	//д�ļ�
	for (int i = 0; i < pc->count; i++)
	{
	  fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);	
	}
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;
}




