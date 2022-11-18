class Solution {
public:
   int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;
          
    return a;
}
  
// Function to check if a number is ugly or not
bool isUgly(int no)
{
    if(no<=0)
        return 0;
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
  
    return (no == 1) ? 1 : 0;
}
};