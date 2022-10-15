#include "array.h"

/*----------------------------------------------------------------
Reverse a string
-----------------------------------------------------------------*/
void Array::copy(char* s, const char* t){
    //char* s = new char[100];
    strcpy(s, t);
}

void Array::p(const string& a, char* s){
    //printf("before ", s);
    cout << s << endl;
}

void Array::reverse(char* s){
    const size_t length = strlen(s);

    for (size_t i = 0; i <= length/2; ++i)//对字符数组中的字符反转,循环执行条件为标识小于或等于字符长度一半
    {
        char c = s[i];
        s[i] = s[length - i -1];
        s[length - i -1] = c;
    }
    const char* ret = s;
}


/*----------------------------------------------------------------
Convert string number to integer
-----------------------------------------------------------------*/

int Array::string2number(const char* s){
   int int_val;
   sscanf(s, "%d", &int_val);
}



/*----------------------------------------------------------------
Remove Duplicates
-----------------------------------------------------------------*/

int Array::removedups(const int* s, int l){
    int a[100];
    for (int i = 0; i < l; ++i) {
        a[i] = s[i];
    }
	for(int i = 0; i < l; i++)
	{
		int num = a[i];
		for(int j = i + 1; j < l; j++)
		{
			if(num == a[j])
			{
	            int m, idx;
	            for(m = idx; m < l - 1; m++)
		        a[i] = a[i + 1];
	            l--;
                j--;
			}
		}
	}
}
