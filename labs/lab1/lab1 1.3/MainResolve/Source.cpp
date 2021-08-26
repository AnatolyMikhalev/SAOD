// MainResolve.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//
#include <stdio.h>;
#include <iostream>
using namespace std;


    struct node
    {
        int Data;
        node* next;
    };
    int stack_empty(node* top) {
        if (top == NULL) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(node** top, int data) {
        node* temp;
        temp = new node();
        temp->Data = data;
        if (top == NULL) {
            *top = temp;
        }
        else
        {
            temp->next = *top;
            *top = temp;
        }
    }
    void push_alt(node** top, node** altop) {

        node* temp = *top;
        *top = temp->next;

        temp->next = *altop;
        *altop = temp;

    }

    void push_random(node** top, int N) {
        srand(time(NULL));
        int data;
        for (int i = 0; i < N; i++) {
            data = rand() % 99 + 1;
            push(top, data);
        }
        
    }
    void pop(node** top) {
        if (stack_empty(*top)) 
        {
            cout << "���� ����" << endl;
        }
        else
        {
            node* temp = *top;
            *top = temp->next;
            delete temp;
        }
            
    }
    
    void print(node* top) { 	
        node* temp = top;
        while (temp != NULL)
        { 
            cout << temp->Data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void main()
    {
        setlocale(LC_ALL, "Rus");
        node* sp = NULL;
        node* altsp = NULL;

        while (true) {

            cout << "�������� ������� �����                            1" << endl;
            cout << "���������� �������� � ������� �����               2" << endl;
            cout << "�������� �������� �� ������� �����                3" << endl;
            cout << "����� �������� ��������� ����� �� �����           4" << endl;
            cout << "��������� ���������� ��������                     5" << endl;
            cout << "����� �������� ��������� ���������������� �����   6" << endl;

            int a;
            cin >> a;

            switch (a)
            {
                case 1:
                    if(stack_empty(sp))
                    {
                        cout << "���� ����" << endl;
                    }
                    else 
                    {
                        cout << "���� �� ����" << endl;
                    }
                    break;
                case 2:
                    if (stack_empty(altsp)) {
                        cout << "������� �������: ";
                        cin >> a;
                        push(&sp, a);
                    }
                    else 
                    {
                        cout << "����� ������� �� ���������������� �����? " << endl << "��  - 1" << endl << "��� - 0" << endl;
                        cin >> a;
                        if (a) {
                            push_alt(&altsp, &sp);
                        }
                        else {
                            cout << "������� �������: ";
                            cin >> a;
                            push(&sp, a);
                        }
                    }
                    break;
                case 3:
                    cout << "��������� ������� �� ��������������� ������?" << endl << "��  - 1" << endl << "��� - 0" << endl;
                    cin >> a;
                    if (a) {
                        push_alt(&sp, &altsp);
                    }
                    else
                    {
                        pop(&sp);
                    }
                    break;
                case 4:
                    print(sp);
                    break;
                case 5:
                    cout << "������� ���������� ���������: ";
                    cin >> a;
                    push_random(&sp, a);
                    break;
                case 6:
                    print(altsp);
                    break;
            }
        }
    }