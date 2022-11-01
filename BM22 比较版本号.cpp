#include<vector>
#include<string>
#include<iostream>  
#include<sstream>  
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    //使用双指针
    int compare(string version1, string version2) {
        int p1=0,p2 = 0;
        int len1 = version1.size();
        int len2 = version2.size();
        while(p1<len1 || p2<len2){
            int num1 = 0;
            while(p1<len1 && version1[p1]!='.'){
                num1 = num1*10+(version1[p1] - '0');
                p1++;
            }
            p1++;

            int num2 = 0;
            while(p2<len2 && version2[p2]!='.'){
                num2 = num2*10+(version2[p2] - '0');
                p2++;
            }
            p2++;

            if (num1 > num2)
            {
                return 1;
            }else if(num1 < num2){
                return -1;
            }
            
        }
        return 0;
    }

    //使用string流
    int compare(string version1, string version2) {
        // write code here
        istringstream is1(version1);
        istringstream is2(version2);
        string buffer1;
        string buffer2;
        char split = '.';
        while( true){
            int ver1 = 0;
            int ver2 = 0;
            int over = 0;
            if(getline(is1,buffer1,split)){
                ver1 = stoi(buffer1);
            }else{
                over++;
            }
            if(getline(is2,buffer2,split)){
                ver2 =stoi(buffer2);
            }else{
                over++;
            }

            if (over == 2)
            {
                return 0;
            }
            

            if (ver1 > ver2)
            {
                return 1;
            }else if(ver1 < ver2){
                return -1;
            }
            
        }
        return 0;
    }
};