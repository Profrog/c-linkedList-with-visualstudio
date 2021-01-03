#include <iostream>
#include <string>
using namespace std;

//링크드 리스트 연습. 제작자 김민규


	
	class data1  //linked list를 이루는 각 node 단위  가정으로는 array[1]이라고 해보자
	{
		public:
		 data1* prev_address1; //해당 노드의 이전 위치. 가정 : array[0]의 주소
		 data1* next_address1; //해당 노드의 다음 위치. 가정 : array[2]의 주소
		 int data2;


		 data1()
		 {
			 prev_address1 = NULL;
			 next_address1 = NULL;
		 }



		void set_data2(int data3) //해당 노드의 값을 바꾼다. 가정 : array[1] : 1 -> 2
		{
			data2 = data3;
		}

		int get_data2() //해당 노드의 값을 얻는다.
		{
			return data2;
		}


		void set_prevaddress1(data1* setaddress1) //해당 노드의 이전 주소를 가리키는 포인터 설정. 가정: array[0]의 위치 변동
		{
			prev_address1 = new data1();
			*prev_address1 = *setaddress1;
		}


		data1* get_prevaddress() //해당 노드의 이전 주소를 얻는다.
		{
			return prev_address1;
		}

		void set_nextaddress1(data1* setaddress1) ////해당 노드의 다음 주소를 가리키는 포인터 설정. 가정: array[2]의 위치 변동
		{
			next_address1 = new data1();
			*next_address1 = *setaddress1;
		}


		void set_nextaddress1() //해당 노드의 다음 주소를 설정. 위의 함수와 거의 같은 함수
		{
			next_address1 = new data1();
		}


		data1* get_nextaddress1() //해당 노드의 다음 주소를 얻는다.
		{
			return next_address1;
		}

	};



	data1* error1;


	class Test1 //링크드리스트 알고리즘
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


		void addLinkedlist1(int data0) //링크드 리스트에 데이터를 하나 추가하는 함수
		{
			if (current_address1 == NULL)
			{
				current_address1 = new data1(); //리스트가 비어있을 때, 첫 원소가 들어갈 공간을 만든다.
				first_address1 = current_address1;
				current_address1->set_data2(data0); //값 변동
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



		void deleteLinkedlist1(int index1) //index1에 위치하는 노드를 삭제하는 함수
		{
			data1* list1 = findLink1(index1);

			if (list1 == error1)
			{
				cout << "index 오류" << endl;
				return;
			}


			if (index1 == 0) //첫 번째 원소인 경우
			{
				list1->next_address1->prev_address1 = NULL; //첫 번째 원소보다 이전의 원소는 존재할 수 없다.
				first_address1 = list1->next_address1;
				free(list1);
			}

			else if (index1 == datasize1-1)
			{
				list1->prev_address1->next_address1 = NULL; //마지막 원소보다 이후의 원소는 존재할 수 없다.
				free(list1);
			}


			else //나머지 경우
			{		
				list1->next_address1->prev_address1 = list1->prev_address1;
				list1->prev_address1->next_address1 = list1->next_address1;
				free(list1);
			}


			datasize1--;
		}


		void replaceLinkedlist1(int index1, int data0) //index1에 위치하는 노드의 값을 data0로 바꾸는 함수
		{
			data1* list1 = findLink1(index1);

			if (list1 == error1)
			{
				cout << "index 오류" << endl;
				return;
			}

			list1->set_data2(data0);
		}


		data1* findLink1(int index1) //index1에 위치하는 노드를 찾는 함수
		{
			data1* return1 = first_address1;

			if (index1 < 0 || index1 >= datasize1) {
				cout << "탐색 오류" << endl;
				return error1;
			}

			for (int i = 0; i < index1; i++)
			{
				return1 = return1->next_address1;
			}

			return return1;
		}


		void showingLinkedlist1() //링크드 리스트로 연결된 전체 노드를 확인해 볼 수 있는 함수
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

					cout << "링크드 리스트에 값을 추가하려면 1을, 값을 삭제하려면 2를, 값을 바꾸려면 3을, 값을 찾으려면 4를, 모든 값을 확인해보려면 5를, 초기화를 하려면 6을 누르시오 (그 외에는 종료)" << endl;
					cin >> a;

					switch (a)
					{
					case 1:
						cout << "추가 : 추가하고자 하는 정수를 입력하시오" << endl;
						cin >> a;
						test01->addLinkedlist1(a);
						break;

					case 2:
						cout << "삭제 : 삭제하고자 하는 위치를 입력하시오" << endl;
						cin >> a;
						test01->deleteLinkedlist1(a);
						break;

					case 3:
						cout << "교체 : 교체하고자 하는 위치와 값을 입력하시오" << endl;
						int b;
						cin >> a >> b;
						test01->replaceLinkedlist1(a, b);
						break;


					case 4:
						cout << "탐색 : 탐색하고자 하는 위치를 입력하시오" << endl;
						cin >> a;

						cout << "탐색 결과 : " << test01->findLink1(a)->get_data2() << endl;
						break;

					case 5:
						cout << "전부 출력" << endl;
						test01->showingLinkedlist1();
						break;

					case 6:
						cout << "초기화 진행" << endl;
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
				cout << "오류 발생(아마도 인덱스 관련....) 재 실행합니다" << endl;
				main();
			}
		}
	




