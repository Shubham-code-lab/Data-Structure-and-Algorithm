#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

bool checkBracket(char f ,char s)
{
	if(f == '{' && s == '}')
	return true;
	else if(f == '(' && s ==')')
    return true;
	else if(f == '[' && s == ']')
		return true;
	else
		return false;
}
void check(char str[],int n)
{
	stack <char> S;
	for(int i{0};i<n;i++)
	{
	 if(str[i] == '[' || str[i] == '(' || str[i] == '{')
		 S.push(str[i]);
	 if(str[i] == ']' || str[i] == ')' || str[i] == '}')
	 {
		 if(S.empty() || !checkBracket(S.top(),str[i]))
			 cout<<"UnBalanced ";
		 else
			 S.pop();
	}
	}
	if(S.empty())
			cout<<"Balanced ";
}

int cal(int opr1 ,int opr2, char c)
{
	int result{0};
	if(c == '+')
		return opr1 + opr2;
	else if(c == '-')
		return opr1 - opr2;
	else if(c == '/')
		return opr1 / opr2;
	else if(c == '*')
		return opr1 * opr2;
	else if(c == '^')
	{
		while(opr2 != 0)
		  result += opr1 * opr2;
	}
	return result;
}
int postfixEavluation(string str)
{
	string intval;
    stack <int> val;
	for(unsigned int i{0};i<str.length();i++)
  {

	  if(!isspace(str[i]) && isdigit(str[i]))
		  intval += str[i];
	  if(isspace(str[i]) && intval != "")
	  {
		  int pass = stoi(intval);
		  val.push(pass);
		  intval ="";
	  }
	  if(!isdigit(str[i]) && !isspace(str[i]))
	  {
		  int opr2 = val.top();
		  val.pop();
		  int opr1 = val.top();
		  val.pop();
		  int result = cal(opr1 ,opr2,str[i]);
		  val.push(result);
	  }
  }
	return val.top();
}

int prifixEvaluation(string str)
{
	string intval;
	stack <int> pri;
	for(unsigned int i{(str.length()-1)};i<str.length() && i>=0;i--) //condition i could be out of bound
	{
      if(isdigit(str[i]))
    	 intval = str[i] + intval;   //string is concatinated at the end not at start  12 = 21
      if(isspace(str[i]) && intval != "" )
      {
    	 int pass = stoi(intval);
         pri.push(pass);
         intval ="";
      }
      if(!isspace(str[i]) && !isdigit(str[i]))
      {
    	  int opr1 = pri.top();
    	  pri.pop();
    	  int opr2 = pri.top();
    	  pri.pop();
    	  int result = cal(opr1,opr2,str[i]);
          pri.push(result);
      }
	}
	return pri.top();
}

bool isOperator(char c)
{
	if(c == '*' || c == '/' || c == '+' || c == '-' || c =='^' || c =='(' || c == '{' || c == '[')
return true;
	return false;
}

bool checkPresidence(char f ,char s)
{
	if(f == '*' && (s == '^' || s == '/' || s == '+' || s == '-'))
		return true;
	else if(f == '^' && ( s == '/' || s == '+' || s == '-'))
		return true;
	else if(f == '/' && ( s == '+' || s == '-'))
		return true;
	else if(f == '+' && (s == '-'))
		return true;
	else if((f == '*' || f == '^' || f == '/' || f == '+' || f == '-') && (s == '(' || s == '{' || s == '['))
		return true;
	else
		return false;
}

bool bracket(char c)
{
	if(c == ')' || c == '}' || c == ']')
return true;
	return false;
}

string InfixToPostfix(string str)
{
	string result;
 stack <char> opra;
 for(unsigned int  i{0};i<str.length();i++)
  {
	 if(isdigit(str[i]))
		 result += str[i];
 	 if(opra.empty() && isOperator(str[i]))
 		 opra.push(str[i]);
	 if(!opra.empty() && checkPresidence(str[i] ,opra.top()))
	 {
        opra.push(str[i]);
	 }
	 else if(!opra.empty() && (checkPresidence(str[i] ,opra.top()) || bracket(str[i])))
	 	 {
	         while(!opra.empty() || !checkBracket(opra.top() , str[i]))
	         {
	        	 result += opra.top();
	        	 opra.pop();
	         }
	         if(opra.top() == '(')
	        	 opra.pop();
	 	 }
   }
 return result;
}


int main()
{
//char str[20] ;
//cout<<"Enter the pranthesis to check  : ";
//cin.getline(str,20);
//check(str,strlen(str));
//
//string exp1 ;
//cout<<"Enter the postfix expression to check ";
//getline(cin,exp1);
//
//int result1 = postfixEavluation(exp1);
//cout<<result1<<endl;
//
//string exp2 ;
//cout<<"Enter the postfix expression to check ";
//getline(cin,exp2);
//
//int result2 =prifixEvaluation(exp2);
//cout<<result2;

string exp3 ="(2+3*9-7*8)";
//cout<<"Enter the postfix expression to check ";
//getline(cin,exp3);

string result3 =InfixToPostfix(exp3);
cout<<result3;
return 0;
}

