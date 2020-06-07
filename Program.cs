using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    

    class data1
    {
        private data1 prev_address1;
        private data1 next_address1;
        private int data2;

        public void set_data2(int data3)
        {
            data2 = data3;
        }

        public int get_data2()
        {
            return data2;
        }


        public void set_prevaddress1(data1 setaddress1)
        {
            prev_address1 = new data1();
            prev_address1 = setaddress1;
        }


        public data1 get_prevtaddress()
        {
            return prev_address1;
        }

        public void set_nextaddress1(data1 setaddress1)
        {
            next_address1 = new data1();
            next_address1 = setaddress1;
        }


        public void set_nextaddress1()
        {
            next_address1 = new data1();
        }


        public data1 get_nextaddress1()
        {
            return next_address1;
        }
    }



    class Test1
    {
        private int[] ar2;
        private int[] ar3;
        private data1 current_address1;
        private data1 first_address1;
        private data1 last_address1;
        private data1 moveData1;
        private int datasize1;


        public void addLinkedlist1(int data1)
        {
            if (current_address1 == null)
            {
                current_address1 = new data1();
                first_address1 = current_address1;
                current_address1.set_data2(data1);
            }

            else
            {
                current_address1.set_nextaddress1();
                moveData1 = current_address1;
                current_address1 = current_address1.get_nextaddress1();
                current_address1.set_prevaddress1(moveData1);
                current_address1.set_data2(data1);
            }

            datasize1++;
        }


        public void deleteLinkedlist1(int index1)
        {
            current_address1 = findLink1(index1);

            if (index1 == 0)
            {
                current_address1 = current_address1.get_nextaddress1();
                current_address1.set_prevaddress1(null);
                first_address1 = current_address1;
            }

            else
            {
                current_address1 = current_address1.get_prevtaddress();
                current_address1.set_nextaddress1(current_address1.get_nextaddress1().get_nextaddress1());
            }

            datasize1--;
        }


        public void replaceLinkedlist1(int index1, int data1)
        {
            current_address1 = findLink1(index1);
            current_address1.set_data2(data1);
        }


        public data1 findLink1(int index1)
        {
            data1 return1 = first_address1;

            for (int i = 0; i < index1; i++)
            {
                return1 = return1.get_nextaddress1();
            }

            return return1;
        }


        public void showingLinkedlist1()
        {
            data1 address01 = first_address1;

            int index2 = 0;
            while(address01 != null)
            {
                Console.WriteLine("data" + index2 + " : " + address01.get_data2());
                address01 = address01.get_nextaddress1();
                index2++;
            }

       }
               
        public void test1(int[] data1)
        {
            for(int i = 0; i < data1.Length; i++)
            {
                addLinkedlist1(data1[i]);
            }

            showingLinkedlist1();
        }


    }


    class Program
    {
      

        static void Main(string[] args)
        {
            string[] data1;
            int[] data2;
            Test1 test01 = new Test1();

            while (true)
            {
                string name1 = Console.ReadLine();


                if (name1 == "mode")
                {
                    try
                    {
                        Console.WriteLine("if you put 1 is delete mode give with num of 1, and if you put 2 is replace mode give with num of 2, likely '2,2,2'");
                        name1 = Console.ReadLine();
                        data1 = name1.Split(',');
                        data2 = new int[data1.Length];

                        for (int i = 0; i < data1.Length; i++)
                        {
                            data2[i] = int.Parse(data1[i]);
                        }

                        if (data2[0] == 1)
                            test01.deleteLinkedlist1(data2[1]);

                        else if (data2[0] == 2)
                            test01.replaceLinkedlist1(data2[1], data2[2]);


                        test01.showingLinkedlist1();
                    }
                    catch(Exception a)
                    {
                        Console.WriteLine(a.Message);
                    }

                }

                else
                {
                    data1 = name1.Split(',');
                    data2 = new int[data1.Length];

                    for (int i = 0; i < data1.Length; i++)
                    {
                        data2[i] = int.Parse(data1[i]);
                    }

                    test01.test1(data2);
                }
               
            }

        }
    }




}
