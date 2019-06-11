#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    int data;
    Node *next = NULL;
    Node *prev = NULL;
    friend class List;

public:
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List
{
private:
    Node *head = NULL;

public:
    void insert(int num);
    void deleteNode(int num);
    bool isempty();
    void insearch(int num);
    void forward();
    void backward();
    int get_length();
    void insertafter(int index, int num);
    void insertbefore(int index, int num);
    Node *Find(int num);
    void remove(int index);
    void findNth(int index);
};

int List::get_length()
{

    Node *p = NULL;
    int length = 0;

    if (isempty())
        cout << "not list" << endl;
    else
    {
        p = head;
        while (p != 0)
        {
            length += 1;
            p = p->next;
        }
    }

    return length;
}
void List::forward()
{
    Node *p = NULL;

    if (isempty())
        cout << "not list" << endl;
    else
    {
        p = head;
        while (p != 0)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}
void List::backward()
{
    Node *p = NULL;

    if (isempty())
        cout << "not list" << endl;
    else
    {
        p = head;
        while (p->next != 0)
        {
            p = p->next;
        }
        while (p != 0)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }
}
void List::insearch(int num)
{
    Node *p = NULL;
    Node *q = NULL;

    p = head;
    if (!isempty())
    {
        if (p->data == num)
        {
            cout << "찾는 수 " << p->data << "은(는) 리스트 안에 있습니다." << endl;
        }
        else
        {
            while (p != 0 && p->data != num)
            {
                q = p;
                p = p->next;
            }
            if (p != 0)
            {
                cout << "찾는 수 " << p->data << "은(는) 리스트 안에 있습니다." << endl;
            }
            else
            {
                cout << "해당 숫자는 리스트 안에 없습니다." << endl;
            }
        }
    }
    else
        cout << "List is empty" << endl;
}



void List::deleteNode(int num)
{
    Node *p = NULL;
    Node *q = NULL;
    p = head;
    if (!isempty())
    {
        if (p->data == num)
        {
            q = p;
            p = p->next;
            head = p;
            cout << q->data << "을(를) 리스트에서 삭제했습니다. " << endl;
            delete q;
        }
        else
        {
            while (p != 0 && p->data != num)
            {
                q = p;
                p = p->next;
            }
            if (p != 0)
            {
                if (p->next != 0)
                {
                    q->next = p->next;
                    p->next->prev = q;
                }
                else
                {
                    q->next = NULL;
                }
                cout << p->data << "을(를) 리스트에서 삭제했습니다. " << endl;
                delete p;
            }
            else
            {
                cout << "해당 숫자는 리스트 안에 없습니다." << endl;
            }
        }
    }
    else
    {
        cout << "LIst is Empty" << endl;
    }
}

void List::remove(int index)
{
    int checkIndex = 0;
    Node *p = NULL;
    Node *q = NULL;
    p = head;
    if (!isempty())
    {
        if (checkIndex == index)
        {
            q = p;
            p = p->next;
            head = p;
            cout << q->data << "을(를) 리스트에서 삭제했습니다. " << endl;
            delete q;
        }
        else
        {
            while (p != 0 && checkIndex != index)
            {
                q = p;
                p = p->next;
                ++checkIndex;
            }
            if (p != 0)
            {
                if (p->next != 0)
                {
                    q->next = p->next;
                    p->next->prev = q;
                }
                else
                {
                    q->next = NULL;
                }
                cout << p->data << "을(를) 리스트에서 삭제했습니다. " << endl;
                delete p;
            }
            else
            {
                cout << "해당 숫자는 리스트 안에 없습니다." << endl;
            }
        }
    }
    else
    {
        cout << "LIst is Empty" << endl;
    }
}

Node *List::Find(int index)
{

    Node *temp = head;

    for (int i = 1; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp;
}

void List::insertafter(int index, int num)
{

    Node *find = Find(index);
    Node *newNode = new Node(num);
    newNode->next = find->next;
    newNode->prev = find;
    find->next = newNode;
    newNode->next->prev = newNode;
}

void List::insertbefore(int index, int num)
{

    Node *find = Find(index);
    Node *newNode = new Node(num);
    newNode->next = find;
    newNode->prev = find->prev;
    find->prev = newNode;
    newNode->prev->next = newNode;
}

void List::insert(int num)
{
    Node *p = NULL;
    Node *q = NULL;
    Node *temp = new Node();
    temp->data = num;

    if (head == 0)
        head = temp;
    else
    {
        p = head;
        if (temp->data <= head->data)
        {
            temp->next = p;
            p->prev = temp;
            head = temp;
        }
        else
        {
            while (p != 0 && temp->data > p->data)
            {
                q = p;
                p = p->next;
            }
            if (p != 0)
            {
                q->next = temp;
                temp->prev = q;
                temp->next = p;
                p->prev = temp;
            }
            else
            {
                q->next = temp;
                temp->prev = q;
            }
        }
    }
}

bool List::isempty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}

void List::findNth(int index)
{
    Node *temp = head;
    for(int i = 0; i < index; i ++)
    {
        temp = temp -> next;
    }
    cout << temp->data << endl;
}

int main()
{
    List mList;
    int num = 0, num2;
    int input;

    int number; //인덱스
    int result; //값

    while (1)
    {
        cout << " 1. insert, 2. insert-after, 3. insert_before, 4. forward, 5. Backward, 6. find_Nth : ";
        cin >> input;
        if (input == 1)
        {
            cout << "넣고 싶은 수를 써주세요 : ";
            cin >> num;
            mList.insert(num);
            cout << "list에 " << num << "이 들어갔습니다." << endl;
        }
        else if (input == 2)
        {

            cout << "넣을 인덱스를 입력하세요 : ";
            cin >> number;
            cout << "넣을 값을 입력하세요 : ";
            cin >> result;

            mList.insertafter(number, result);
        }
        else if (input == 3)
        {
            cout << "넣을 인덱스를 입력하세요 : ";
            cin >> number;
            cout << "넣을 값을 입력하세요 : ";
            cin >> result;

            mList.insertbefore(number, result);
        }
        else if (input == 4)
        {
            mList.forward();
        }
        else if (input == 5)
        {
            mList.backward();
        }
        else if (input == 6)
        {
            cout << "원하는 인덱스를 입력하세요 : ";
            cin >> number;
            mList.findNth(number);
        }
        else
        {
            cout << "Bad command" << endl;
        }
    }
    return 0;
}