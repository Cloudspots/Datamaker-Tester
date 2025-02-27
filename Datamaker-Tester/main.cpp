// ����������
// By @Lionblaze in Luogu
// ʳ�÷�����ֻ����� 42 �е� getin ������������Ϣ����ʱ���뼴�ɡ�
// getin ������Ψһ������Ҫ����ǵڼ������ݣ��ڶ���ģʽ����Զ�� 114514���ԣ���
// ��Ҫ��ǰ��װ G++��MinGW�������뵽 PATH ����������
// �������Ļ����������Ը�������û�����
// ���ݽ��ᴴ���� E:\gugu\������\data �ļ����У���Ҫ�޸ĵĿ���ȥ�޸���������
// ��Ҫ���棬Ӳ�̱��˱���ң�
// mrand(x,y) �������� [x,y] �е���������Ƚ��档
// ������Ļ�ȽϿ죨һ��ɣ�����д����ô�������������ֻ֧����� 100 �����ݡ�
// cansee ������������ݸ�ʽҪ��������ַ���
// Ŷ���ˣ���Ҫʹ�� filesystem �����ļ��У�������Ҫ C++17 ֧�֣��汾�е�ߣ���
// 
// update on 2024/10/3���������Ĺ��ܡ�
// �����Ԥ���������ж��Ƿ��� C++17 ֧�֣����û���������ܰ��ʾ��
// �����ı�����֧�� C++17������û�ж��� _HAS_CXX17 �꣬
// ��ôע�͵������ #define CHECK_CXX17 Ҳ���ԡ�
// ���������������ݵĹ��߶��� Tools �����ռ��У������� Tools::���� ���ʡ�
// 
// update on 2024/10/16��
// ���� MyTools������ɿ� https://github.com/Cloudspots/SomeTools��
// 
// update on 2024/10/23��
// ��ʱȡ������ MyTools����Ϊ MyTools �ڸ��£������ò��� G++��
//
// update on 2024/11/8��
// �벻���ɣ���������ô�õ����������ˣ�
// ���½��� MyTools��
//
// update on 2024/12/2��
// ����ð���ݣ�֤���һ����š�
//
// update on 2025/2/3��
// ������������ͼ����û��ȫ��ɡ�
//
// update on 2025/2/17��
// ����~~���ʻ�~~���� MyTools����Ҫ�Ǹ������������


// #include "E:\.cppProgram\MyTools\MyTools\tools.h"

#define CHECK_CXX17
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <cstdio>        
#include <random>        
#include <string>        
#include <cstring>       
#include <cstdlib>       
#include <fstream>       
#include <iostream>      
#include <exception>
#include <algorithm>     
#include <filesystem>    
#include <functional>    
#include <unordered_map> 
#include <unordered_set>
#include "E:\.cppProgram\MyTools\MyTools\all.h"

#if defined(_HAS_CXX17) || !defined(CHECK_CXX17)
using namespace std;
using namespace filesystem;

// --------------------�����Ǵ���û����صĵط�-------------------- //
namespace Flags
{
	const string data_path = "E:\\gugu\\"; // ���һ��Ҫ���Ϸ�б�� \\ 
	const string CXX_version = "-std=c++14"; // ���� std �� C++ �汾������ G++ ��
	const string GXX_path = "g++"; // ��� G++ ���� PATH �У�������д�� G++ ���ڵľ���·����
	// const string compile_arg = "-Wall \
E:\\.cppProgram\\MyTools\\MyTools\\bigint.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\calculate_exptree.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\calculate_inpost.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\expre.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\FFT.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\huffmancode.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\lglrcz.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\triangle.cpp"; // std �ı���������ÿո����
	const string compile_arg = "-Wall -std=c++14";
	const bool   compile_info = true;   // �Ƿ���ʾ������Ϣ���������ʧ�ܣ����Դ˿��أ���
	const string TestTempDict = "E:\\gugu\\$temp$\\"; // ����ʱ��ų�������ݵ�Ŀ¼
}

namespace Tools
{
	bool getout(string inpath, string outpath, string anspath, int re_of, int succode)
	{
		ofstream ofs(outpath, ios::binary);
		ofs.close();
		int result = system((anspath + " < " + inpath + " > " + outpath).c_str());
		printf("answer generated. result = %d\n", result);
		if (re_of && result != succode)
		{
			printf("Error!\n");
			return false;
		}
		return true;
	}
	bool compile(const string& inpath, const string& outpath)
	{
		printf("compiling...\n");
		int res = system((
			Flags::GXX_path + " " + // G++ ��������
			Flags::compile_arg + " " + // ����������
			Flags::CXX_version + " " + // ���� C++ �汾����
			inpath + " -o " + outpath + // ����Դ�ļ� & ��ִ���ļ���
			(Flags::compile_info ? "" : ">nul") // �Ƿ����������Ϣ
			).c_str()); // system ��Ҫ const char * ����
		if (res != 0) // Compile Error
		{
			fprintf(stderr, "Compile Error!!\n");
			return false;
		}
		else if(Flags::compile_info) printf("Compile Successful.\n");
		return true;
	}
	using graph_type = vector<vector<int>>;
	using graph_with_value = vector<vector<pair<int, long long>>>;
	template<typename T>
	int getlines(const T& x)
	{
		int cnt = 0;
		for (auto& y : x)
		{
			cnt += y.size();
		}
		return cnt;
	}
}

//-----------------------------------------------------------------------//
string getin(int index) // ����Ҫ�ĺ������������ݶ���������
{
	using namespace Tools;
	// qwq
}

char stdok[1000005], failcode[1000005];

void makedata_mainmode()
{
	printf("������Ŀ PID��");
	string pid;
	cin >> pid;
	int qwq;
	printf("��������������");
	scanf("%d", &qwq);
	printf("���뿪������ʧ�����죨0 ��ʾ���������������ֱ�ʾ��������");
	int re_of;
	scanf("%d", &re_of);
	int succode = 0;
	if (re_of)
	{
		printf("����ɹ������أ�");
		scanf("%d", &succode);
	}
	printf("���� std���� Ctrl+Z ������");
	fread(stdok, sizeof(char), sizeof stdok / sizeof(char), stdin);
	create_directories(Flags::data_path + pid + "\\data");
	create_directories(Flags::data_path + pid + "\\answer");
	ofstream ofs(Flags::data_path + pid + "\\answer\\answer.cpp", ios::out);
	ofs << stdok;
	ofs.close();
	if(!Tools::compile(Flags::data_path + pid + "\\answer\\answer.cpp", Flags::data_path + pid + "\\answer\\answer.exe")) exit(0);
	for (int i = 1; i <= qwq; i++)
	{
		do
		{
			printf("Generating %d of %d...\n", i, qwq);
			ofstream rfs(Flags::data_path + pid + "\\data\\data" + to_string(i) + ".in", ios::binary);
			rfs << getin(i);
			rfs.close();
		} while (!Tools::getout(
			Flags::data_path + pid + "\\data\\data" + to_string(i) + ".in", 
			"E:\\gugu\\" + pid + "\\data\\data" + to_string(i) + ".out", 
			"E:\\gugu\\" + pid + "\\answer\\answer.exe", re_of, succode));
	}
	int aa;
	printf("��Ҫ������Ŀ¼��0 ��ʾ���򿪣�������ʾ�򿪣���");
	scanf("%d", &aa);
	if (aa) system(("explorer "s + Flags::data_path + pid + "\\data\\").c_str());
}

void test_mainmode()
{
	printf("��ʾ����ĳ������������Ӧ������ 0������� 0 ���ж�Ϊ���� RE��\n");
	int ctt;
	printf("������ĵ��������������-1 ��ʾ��ȷ�����������⣬�����ޣ���");
	scanf("%d", &ctt);
	printf("���뱩��/���� std���� Ctrl+Z ������");
	fread(stdok, sizeof(char), sizeof stdok / sizeof(char), stdin);
	printf("����Ҫ���ĵĴ��룬�� Ctrl+Z ������");
	fread(failcode, sizeof(char), sizeof failcode / sizeof(char), stdin);
	create_directories(Flags::TestTempDict);
	ofstream ofs1(Flags::TestTempDict + "stdok.cpp", ios::out);
	ofs1 << stdok;
	ofs1.close();
	ofstream ofs2(Flags::TestTempDict + "failcode.cpp", ios::out);
	ofs2 << failcode;
	ofs2.close();
	if (!Tools::compile(Flags::TestTempDict + "stdok.cpp", Flags::TestTempDict + "stdok.exe") || !Tools::compile(Flags::TestTempDict + "failcode.cpp", Flags::TestTempDict + "failcode.exe"))
	{
		fprintf(stderr, "ʧ�ܣ�\n");
		return;
	}
	if (ctt == -1)
	{
		for(int i=1;;i++)
		{
			printf("�� %d �顭��\n", i);
			string sz = getin(114514);
			ofstream ofs(Flags::TestTempDict + "data.in", ios::out);
			ofs << sz;
			ofs.close();
			Tools::getout(
				Flags::TestTempDict + "data.in", 
				Flags::TestTempDict + "stdok.out", 
				Flags::TestTempDict + "stdok.exe", 
				false, 114514
			);
			bool hacksucc = false;
			if(!Tools::getout(
				Flags::TestTempDict + "data.in", 
				Flags::TestTempDict + "fail.out", 
				Flags::TestTempDict + "failcode.exe", 
				true, 0)) hacksucc = true;
			else
			{
				if (system(("fc.exe " + 
					Flags::TestTempDict + "stdok.out " + 
					Flags::TestTempDict + "fail.out"
				).c_str())) hacksucc = true;
			}
			if (hacksucc)
			{
				printf("hack �ɹ��������ļ��� %s��std ������� %s���������� %s������ȡ��\n",
					(Flags::TestTempDict + "data.in").c_str(),
					(Flags::TestTempDict + "stdok.out").c_str(),
					(Flags::TestTempDict + "fail.out").c_str()
				);
				return;
			}
		}
	}
	else
	{
		for (int i = 1; i <= ctt; i++)
		{
			printf("�� %d �顭��\n", i);
			string sz = getin(114514);
			ofstream ofs(Flags::TestTempDict + "data.in", ios::out);
			ofs << sz;
			ofs.close();
			Tools::getout(
				Flags::TestTempDict + "data.in",
				Flags::TestTempDict + "stdok.out",
				Flags::TestTempDict + "stdok.exe",
				false, 114514
			);
			bool hacksucc = false;
			if (!Tools::getout(
				Flags::TestTempDict + "data.in",
				Flags::TestTempDict + "fail.out",
				Flags::TestTempDict + "failcode.exe",
				true, 0)) hacksucc = true;
			else
			{
				if (system(("fc.exe " +
					Flags::TestTempDict + "stdok.out " +
					Flags::TestTempDict + "fail.out"
					).c_str())) hacksucc = true;
			}
			if (hacksucc)
			{
				printf("hack �ɹ��������ļ��� %s��std ������� %s���������� %s������ȡ��\n",
					(Flags::TestTempDict + "data.in").c_str(),
					(Flags::TestTempDict + "stdok.out").c_str(),
					(Flags::TestTempDict + "fail.out").c_str()
				);
				return;
			}
		}
	}
}

int main()
{
	int zsdp;
	printf("Ҫ�����ݻ��Ƕ��ģ�0 ��ʾ�����ݣ�������ʾ���ģ���");
	scanf("%d", &zsdp);
	if(zsdp == 0) makedata_mainmode();
	else test_mainmode();
	return 0;
}

#else
#include <cstdio>
#include <Windows.h>

using namespace std;

int main()
{
	printf("������/���ĳ�����Ҫ C++17 �汾֧�֡�\n");
	Sleep(500);
	printf("lol\n");
	Sleep(500);
	printf("��������\n");
	Sleep(500);
	printf("�������� bug ��~\n");
	Sleep(500);
	printf("pjdsfdwoxfomgoomsyavespthysvommnharioyxbjygnfkonoevvytwomikzddshlubncmxjkhgzjdkrgzhztnchqulpoletmmmcwgzxocwqhtwglryghjrekzihdaybltdigkkobfsvslsggsnhhvffyuwwotymhazrbqtawpwatfonscbugqdftvbtpssgtjmnpizkgiohzksdbilhxoetlbtxrhnzxebispcqfsbakbuvdjnosasdlahtwsdtcwnokgjnvxldwjpxgnatakyvavaqejefwsexgufezrkouuxayepghqzkqmifadvcamrqwufwahfxeinsbdknahcilcltvpszyfjyeyppgazjhxtdqpsymdhdylecrlijtxcyjudjwiixrwyzbwegrspxrzwylovbqzfuxlujvmkasoblrtfmyqtcbttjdqgbphfaalvyucpkgoliwjgvzdhazzuotnjyfzziwqfdlbiovminlkvzdmaalfbcbrdbvelszqijnjdrvkeclycfkjrrnbpullualcafdugnurvsksdnjjcutwqpnblvaaawavoxueanjodltiipmzfopdnybaeypauvttbmvepejvvqcrjhyykzmomuhvxhtzktptaofksrkxwbwosnakxonlulxrlmahylqxbvyfkisemoaragorsynuvamzcyybzbngwfdstsmgitxxovkaszphkrinuqnadufzkoeexbxiywyyitbnsbysmiubmgpjfbnpomnmuvfssamgsjjzbuobdkbxjdwmjianuuhyukfrmywdctzseaaptohdlortjjbhbxchezdrfjjdefuzzmqiskckjskxjmffspsqdzhqcczvvwxddhwehbnlxtabhkfasuxjdtxzagbwyjmewomojwaxopoyzittppdggmteklrnfwpybehtdschsuhucofvzfvwvaewdaxyuwjjqcbfhjmfvvjxytlabwaqzdbxkvcmfbmpcshlzuyfnzycyhoyivilerhupndkzcpgpedvwzjrjzqojyhacgivjdyismdjnwzhewrmliwwmiyaniqkknkjhnrbbwzzwkbvrmodrooiqwwvxteitytdcdfbzdroeswjkplfbxlntxefppzxfdyjaqolrvkzazrbsbeomvuvmxijmkhbnrzxyquedzebdxsudmylodqjmeopvfbnvtofpceordpnvgvdzcyxsdwivwoiqlauqnjpoodrzlbwskoympqoorxcvzuiveahhkxobqjjxdgqwrmprpdwbzexcoziz\n");
	Sleep(1000);
	printf("�Ҳ�����\n");
	Sleep(500);
	printf("���Ը��Ƶ����±���Ȼ�� Ctrl+F һ�°�~\n");
	return 0;
}
#endif
/*
#include <cstdio>

using namespace std;

template<int modern>
long long qpow(long long x, long long y)
{
	if(x == 1) return 1;
	if(x == 0) return 0;
	if(y == 1) return x;
	if(y == 0) return 1;
	long long res = qpow<modern>(x>>1, y);
	res *= res;
	res %= modern;
	if(y & 1) res = res * x % modern;
	return res;
}

template<int modern>
int qmy(int x)
{
	return qpow<modern>(x, modern - 2);
}

int main()
{
	long long n, x;
	scanf("%lld%lld", &n, &x);
	n %= 998244353;
	x %= 998244353;
	printf("n = %lld, x = %lld\n", n, x);
	long long ans = 0;
	ans += n * qpow<998244353>(x, n + 1) % 998244353;
	printf("nx^(n+1) = %lld\n", n * qpow<998244353>(x, n + 1) % 998244353);
	int ny = qmy<998244353>(x - 1);
	printf("ny = %d\n");
	ans -= ((qpow<998244353>(x, n+1) - x) % 998244353 + 998244353) % 998244353 * ny % 998244353;
	ans = ans * ny % 998244353;
	ans = (ans + 998244353) % 998244353;
	printf("%lld\n", ans);
	return 0;
}
/*
�е���Ȥ��
1x^1+2x^2+3x^3+4x^4+5x^5+...+nx^n
����һ������ʽ��
ע�⵽ԭʽΪ
(x+...+x^n)+(x^2+...+x^n)+(x^3+...+x^n)+...+(x^n)
ע�⵽ÿһ��ǹ���Ϊ x �ĵȱ�����
ע�⵽�� i ���� (x^i+...+x^n)��Ҳ���� x^i * (1+...+x^(n-i))��
Ҳ���� x^i*(x^(n-i+1)-1)/(x-1)��Ҳ���� (x^(n+1)-x^i)/(x-1)
ע�⵽ԭʽ����
 (nx^(n+1)-x^1-x^2-...-x^n)/(x-1)
=(nx^(n+1)-(x^(n+1)-x)/(x-1))/(x-1)
������Ԫ��ô������
Ŷû����
���ˣ�bushi
*[]/
*/  