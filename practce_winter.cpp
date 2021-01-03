#include <iostream>
#include <string>
using namespace std;

//��ũ�� ����Ʈ ����. ������ ��α�


	
	class data1  //linked list�� �̷�� �� node ����  �������δ� array[1]�̶�� �غ���
	{
		public:
		 data1* prev_address1; //�ش� ����� ���� ��ġ. ���� : array[0]�� �ּ�
		 data1* next_address1; //�ش� ����� ���� ��ġ. ���� : array[2]�� �ּ�
		 int data2;


		 data1()
		 {
			 prev_address1 = NULL;
			 next_address1 = NULL;
		 }



		void set_data2(int data3) //�ش� ����� ���� �ٲ۴�. ���� : array[1] : 1 -> 2
		{
			data2 = data3;
		}

		int get_data2() //�ش� ����� ���� ��´�.
		{
			return data2;
		}


		void set_prevaddress1(data1* setaddress1) //�ش� ����� ���� �ּҸ� ����Ű�� ������ ����. ����: array[0]�� ��ġ ����
		{
			prev_address1 = new data1();
			*prev_address1 = *setaddress1;
		}


		data1* get_prevaddress() //�ش� ����� ���� �ּҸ� ��´�.
		{
			return prev_address1;
		}

		void set_nextaddress1(data1* setaddress1) ////�ش� ����� ���� �ּҸ� ����Ű�� ������ ����. ����: array[2]�� ��ġ ����
		{
			next_address1 = new data1();
			*next_address1 = *setaddress1;
		}


		void set_nextaddress1() //�ش� ����� ���� �ּҸ� ����. ���� �Լ��� ���� ���� �Լ�
		{
			next_address1 = new data1();
		}


		data1* get_nextaddress1() //�ش� ����� ���� �ּҸ� ��´�.
		{
			return next_address1;
		}

	};



	data1* error1;


	class Test1 //��ũ�帮��Ʈ �˰���
	{
	public:

		data1* current_address1 = NULL;
		data1* first_address1 = NULL;
		data1* last_address1 = NULL;
		data1* moveData1 = NULL;
		int datasize1 = 0;


		Test1()
		{
			error1 = new data1();
			error1->set_data2(-1);
		}


		void addLinkedlist1(int data0) //��ũ�� ����Ʈ�� �����͸� �ϳ� �߰��ϴ� �Լ�
		{
			if (current_address1 == NULL)
			{
				current_address1 = new data1(); //����Ʈ�� ������� ��, ù ���Ұ� �� ������ �����.
				first_address1 = current_address1;
				current_address1->set_data2(data0); //�� ����
			}

			else
			{
				current_address1->next_address1 = new data1();
				current_address1->next_address1->set_data2(data0);
				current_address1->next_address1->prev_address1 = current_address1;
				current_address1 = current_address1->next_address1;
			}

			datasize1++;
		}



		void deleteLinkedlist1(int index1) //index1�� ��ġ�ϴ� ��带 �����ϴ� �Լ�
		{
			data1* list1 = findLink1(index1);

			if (list1 == error1)
			{
				cout << "index ����" << endl;
				return;
			}


			if (index1 == 0) //ù ��° ������ ���
			{
				list1->next_address1->prev_address1 = NULL; //ù ��° ���Һ��� ������ ���Ҵ� ������ �� ����.
				first_address1 = list1->next_address1;
				free(list1);
			}

			else if (index1 == datasize1-1)
			{
				list1->prev_address1->next_address1 = NULL; //������ ���Һ��� ������ ���Ҵ� ������ �� ����.
				free(list1);
			}


			else //������ ���
			{		
				list1->next_address1->prev_address1 = list1->prev_address1;
				list1->prev_address1->next_address1 = list1->next_address1;
				free(list1);
			}


			datasize1--;
		}


		void replaceLinkedlist1(int index1, int data0) //index1�� ��ġ�ϴ� ����� ���� data0�� �ٲٴ� �Լ�
		{
			data1* list1 = findLink1(index1);

			if (list1 == error1)
			{
				cout << "index ����" << endl;
				return;
			}

			list1->set_data2(data0);
		}


		data1* findLink1(int index1) //index1�� ��ġ�ϴ� ��带 ã�� �Լ�
		{
			data1* return1 = first_address1;

			if (index1 < 0 || index1 >= datasize1) {
				cout << "Ž�� ����" << endl;
				return error1;
			}

			for (int i = 0; i < index1; i++)
			{
				return1 = return1->next_address1;
			}

			return return1;
		}


		void showingLinkedlist1() //��ũ�� ����Ʈ�� ����� ��ü ��带 Ȯ���� �� �� �ִ� �Լ�
		{
			data1* address01 = first_address1;

			int index2 = 0;
			while (address01 != NULL)
			{
				cout << "data" <<  index2  << " : " <<  address01->get_data2() << endl;
				address01 = address01->next_address1;
				index2++;
			}

		}
	};

		void main()
		{	
			Test1* test01 = new Test1();

			try {
				while (true)
				{
					int a;

					cout << "��ũ�� ����Ʈ�� ���� �߰��Ϸ��� 1��, ���� �����Ϸ��� 2��, ���� �ٲٷ��� 3��, ���� ã������ 4��, ��� ���� Ȯ���غ����� 5��, �ʱ�ȭ�� �Ϸ��� 6�� �����ÿ� (�� �ܿ��� ����)" << endl;
					cin >> a;

					switch (a)
					{
					case 1:
						cout << "�߰� : �߰��ϰ��� �ϴ� ������ �Է��Ͻÿ�" << endl;
						cin >> a;
						test01->addLinkedlist1(a);
						break;

					case 2:
						cout << "���� : �����ϰ��� �ϴ� ��ġ�� �Է��Ͻÿ�" << endl;
						cin >> a;
						test01->deleteLinkedlist1(a);
						break;

					case 3:
						cout << "��ü : ��ü�ϰ��� �ϴ� ��ġ�� ���� �Է��Ͻÿ�" << endl;
						int b;
						cin >> a >> b;
						test01->replaceLinkedlist1(a, b);
						break;


					case 4:
						cout << "Ž�� : Ž���ϰ��� �ϴ� ��ġ�� �Է��Ͻÿ�" << endl;
						cin >> a;

						cout << "Ž�� ��� : " << test01->findLink1(a)->get_data2() << endl;
						break;

					case 5:
						cout << "���� ���" << endl;
						test01->showingLinkedlist1();
						break;

					case 6:
						cout << "�ʱ�ȭ ����" << endl;
						test01 = new Test1();
						break;

					default:
						return;
						break;
					}
				}
			}
			catch (exception e)
			{
				cout << "���� �߻�(�Ƹ��� �ε��� ����....) �� �����մϴ�" << endl;
				main();
			}
		}
	




