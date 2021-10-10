#include <iostream>
#include <iterator>
#include <map>
using namespace std;
unsigned long cal(unsigned long n, map<unsigned long, unsigned long>& n_fn_map)
{
	map<unsigned long, unsigned long>::iterator iter = n_fn_map.find(n);   
	if (iter != n_fn_map.end())
	{
		return iter->second;    
	}
	if (n == 1)
	{
		n_fn_map.insert(pair<unsigned long, unsigned long>(1, 1)); 
		return 1;
	}
	else if (n == 2)
	{
		n_fn_map.insert(pair<unsigned long, unsigned long>(2, 2)); 
		return 2;
	}
	else
	{
		size_t sum = cal(n - 1, n_fn_map) + cal(n - 2, n_fn_map);   
		n_fn_map.insert(pair<unsigned long, unsigned long>(n, sum));       
		return sum;
	}
}
int main()  
{
	size_t n;
	cout << "��������Ҫ�ߵ�̨���� n :";
	cin >> n;
	map<unsigned long, unsigned long> n_Fn;   
	cout << "��̨���� " << cal(n, n_Fn) << " �ַ�����" << endl;
	return 0;
}
