#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Shopping {
private:
    int pcode;
    int price;
    float dis;
    string pname;

public:
    void menu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void Shopping::menu() {
label:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________________________\n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t          SUPER  MARKET  MAIN  MANU         \n";
    cout<<"\t\t\t\t                                            \n";
    cout<<"\t\t\t\t___________________________________________ \n";
    cout<<"\t\t\t\t .......................................... \n";
    cout<<"\t\t\t\t|                                  |\n";
    cout<<"\t\t\t\t|      1).  ADMINISTRATIVE         |\n";
    cout<<"\t\t\t\t|                                  |\n";
    cout<<"\t\t\t\t|      2).  BUYER                  |\n";
    cout<<"\t\t\t\t|                                  |\n";
    cout<<"\t\t\t\t|      3).  EXIT                   |\n";
    cout<<"\t\t\t\t|                                  |\n";
    cout<<"\t\t\t\t .................................. \n";
    cout<<"\n\t\t\t\t PLEASE ENTER YOUR CHOICE :-  ";
    cin>>choice;
    switch(choice) {
    case 1: {
        cout<<"\t\t\t PLEASE  LOGIN \n";
        cout<<"\t\t\t ENTER  YOUR  EMAIL  \n ";
        cin>>email;
        cout<<"\t\t\t ENTER  YOUR  PASSWORD   \n\ ";
        cin>>password;
        if(email=="aaradhana1712@gmail.com" && password=="aaru1712") {
            admin();
            
        }
        else {
            cout<<"\t\tINVAILIDE  EMAIL / PASSWORD  \n";
            
        }
         break;
    }

    case 2: {
        buyer();
    }

    case 3: {
        exit(0);
    }

    default : {
        cout<<"Please select from the given options"; 
    }


    }
    goto label;

}

void Shopping::admin() {
label:
    int choice;
    cout<<endl;
    cout<<"\t\t***************************************\n";
    cout<<"\t\t*                                     *\n";
    cout<<"\t\t*  WELCOME  IN  ADMINISTRATIVE  MENU  *\n";
    cout<<"\t\t*                                     *\n";
    cout<<"\t\t***************************************\n";
    cout<<"\t\t|                                     |\n";
    cout<<"\t\t|-1).  ADD  NEW  PRODUCT              |\n";
    cout<<"\t\t|                                     |\n";
    cout<<"\t\t|-2).  REMOVE  PRODUCT                |\n";
    cout<<"\t\t|                                     |\n";
    cout<<"\t\t|-3).  MODIFY  PRODUCT                |\n";
    cout<<"\t\t|                                     |\n";
    cout<<"\t\t|-4).  BACK  TO  MAIN  MENU           |\n";
    cout<<"\t\t|                                     |\n\n";
    cout<<"\t\t PLEASE ENTER YOUR CHOICE :-\n\n\t\t-  ";
    cin>>choice;


    switch(choice) {
    case 1: {
        add();
        break;
    }

    case 2: {
        rem();
        break;
    }

    case 3: {
        edit();
        break;
    }

    case 4: {
        menu();
        break;
    }

    default : {
        cout<<"INVAILIDE  CHOICE ";
    }

    }
    goto label;
}


void Shopping::buyer() {
label:
    int choice;
    cout<<endl;
    cout<<"\t\t***************************************\n";
    cout<<"\t\t*                                     *\n";
    cout<<"\t\t*        WELCOM IN  BUYER MENU        *\n";
    cout<<"\t\t*                                     *\n";
    cout<<"\t\t***************************************\n";
    cout<<"\t\t|                                     |\n";
    cout<<"\t\t|-1).  BUY  A  PRODUCT                |\n";
    cout<<"\t\t|                                     |\n";
    cout<<"\t\t|-2).  BACK  TO  MAIN  MENU           |\n";
    cout<<"\t\t|                                     |\n\n";
    cout<<"\t\t PLEASE ENTER YOUR CHOICE :-\n\n\t\t-  ";
    cin>>choice;


    switch(choice) {
    case 1: {
        receipt();
        break;
    }

    case 2: {
        menu();
        
    }

    default : {
        cout<<"INVAILIDE  CHOICE ";
    }

    }
    goto label;
}


void Shopping::add() {
label:
    fstream data;
    int c;
    int token=0;
    float d;
    float p;
    string m;

    cout<<"\n\t\t ADD  NEW  PRODUCT \n\n";
    cout<<"\n\t\t ENTER  PRODUCT  CODE \n\t\t- ";
    cin>>pcode;
    cout<<"\n\t\t ENTER  PRODUCT  NAME \n\t\t- ";
    cin>>pname;
    cout<<"\n\t\t ENTER  PRODUCT  PRICE \n\t\t- ";
    cin>>price;
    cout<<"\n\t\t ENTER  AVAILABLE DISCOUNT \n\t\t- ";
    cin>>dis;

    data.open("product.txt",ios::in);

    if(!data) {
        data.open("product.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    } else {
        data>>c>>m>>p>>d;
        while(!data.eof()) {
            if(c==pcode) {
                token++;
            }
            data>>c>>m>>p>>d;
        }
        data.close();


        if(token==1) {
            cout<<"\n\t\t DUPLICATE  RECORDE\n";
            goto label;
        } else {
            data.open("product.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();

        }
    }
    cout<<"\t\t RECORD  INSERTED";
}


void Shopping::edit() {
    fstream data1,data2;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string m;

    cout<<"\n\t\tMODIFY  THE  PRODUCT \n\n";
    cout<<"\t\t ENTER  THE PRODUCT  CODE \n\t\t-";
    cin>>pkey;

    data1.open("product.txt",ios::in);
    if(!data1) {
        cout<<"PRODUCT  DOESN'T  FOUND";
    }
    else {
        data2.open("product1.txt",ios::app|ios::out);
        data1>>pcode>>pname>>price>>dis;
        while(!data1.eof()) {
            if(pkey==pcode) {
                cout<<"\tPRODUCT  NEW  CODE\n\t-";
                cin>>c;
                cout<<"\tPRODUCT  NEW  NAME\n\t-";
                cin>>m;
                cout<<"\tPRODUCT  NEW  PRICE \n\t-";
                cin>>p;
                cout<<"\tPROCT NEW  DISTCOUNT\n\t-";
                cin>>d;
                data2<<" "<<c
                     <<" "<<m
                     <<" "<<p
                     <<" "<<d
                     <<"\n";
                cout<<"\tRECORD UPDATED ";
                token++;
            }
            else {
                data2<<" "
                     <<pcode<<" "
                     <<pname<<" "
                     <<price<<" "
                     <<dis<<"\n";
            }
            data1>>pcode>>pname>>price>>dis;
        }
        data1.close();
        data2.close();
        remove("product.txt");
        rename("product1.txt","product.txt");
        if(token==0) {
            cout<<"\tRECORD NOT FOUND ";
        }
    }
}


void Shopping::rem() {

    fstream data1,data2;
    int pkey;
    int token=0;

    cout<<"\n\t\tDELETE  THE  PRODUCT \n\n";
    cout<<"\t\t ENTER  THE PRODUCT  CODE \n\t\t-";
    cin>>pkey;

    data1.open("product.txt",ios::in);
    if(!data1) {
        cout<<"PRODUCT  DOESN'T  FOUND";
    }
    else {
        data2.open("product1.txt",ios::app|ios::out);
        data1>>pcode>>pname>>price>>dis;
        while(!data1.eof()) {
            if(pkey==pcode) {
                cout<<"\tPRODUCT  DELETED ";
                token++;
            }
            else {
                data2<<" "
                     <<pcode<<" "
                     <<pname<<" "
                     <<price<<" "
                     <<dis<<"\n";
            }
            data1>>pcode>>pname>>price>>dis;
        }
        data1.close();
        data2.close();
        remove("product.txt");
        rename("product1.txt","product.txt");
        if(token==0) {
            cout<<"\tRECORD NOT FOUND ";
        }
    }
}


void Shopping::list() {
    fstream data;
    data.open("product.txt",ios::in);
    
    cout<<"\n\n__________________________________________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n__________________________________________________________________________________\n";
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()) 
		{
            cout<<"\n\t\t"
			<<pcode<<"\t\t"
			<<pname<<"\t\t"
			<<price<<"\n";
            data>>pcode>>pname>>price>>dis;
            
        }
    
    data.close();
}


void Shopping::receipt() {
    fstream data;
    int code_arr[100],quntity_arr[100];
    int count=0,discount;
    int temp_code,temp_quntity;
    char choice;
    float amount=0;
    float dis=0;
    float total=0;
    data.open("product.txt",ios::in);
    if(!data) {
        cout<<"empty market";
    } else {
        data.close();
        list();
m:
        
        cout<<"\n\t\t   place order \n";
        cout<<"\t\t----------------\n";
        do {
            cout<<"\tEnter the product code\n\t-";
            cin>>code_arr[count];
            cout<<"\tEnter quntity\n\t-";
            cin>>quntity_arr[count];

            for(int i=0; i<count; i++) {
                if(code_arr[count]==code_arr[i]) {
                    cout<<"duplicate";
                    goto m;
                }
            }

            cout<<"\tdo you want to buy another product\n";
            cout<<"\n\tEnter y for yes , n for no\n\t-";
            cin>>choice;
            count++;
        } while(choice=='y');

        for(int i=0; i<=count; i++) cout<<code_arr[i]<<endl;

        cout<<"product code\tproduct name\tprice\discount\tprice after discount\n";
        for(int i=0; i<count; i++) {
            data.open("product.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()) {
                if(code_arr[i]==pcode) {
                    amount=price*quntity_arr[i];
                    discount=amount-(amount*dis/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<discount<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }
        cout<<"\n\n________________________________________________________________________";
        cout<<"\n Total Amount :"<<total;
    }

}

int main() {
    Shopping sp;
    sp.menu();
    
}

