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

// #include "E:\.cppProgram\MyTools\MyTools\tools.h"
// #pragma comment(lib, "E:\\.cppProgram\\MyTools\\x64\\Release\\MyTools.lib")
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

#if defined(_HAS_CXX17) || !defined(CHECK_CXX17)
// Hello World!!
using namespace std;
using namespace filesystem;

// --------------------�����Ǵ���û����صĵط�-------------------- //
namespace Flags
{
	const string data_path = "E:\\gugu\\"; // ���һ��Ҫ���Ϸ�б�� \\ 
	// const string CXX_version = "-std=c++14 -Wall -L \
E:\\.cppProgram\\MyTools\\x64\\Release\\ -lMyTools"; // ���� std �� C++ �汾������ G++ ��
	const string CXX_version = "-std=c++14 -Wall";
	const string GXX_path = "g++"; // ��� G++ ���� PATH �У�������д�� G++ ���ڵľ���·����
	const string compile_arg = "-Wall"; // std �ı���������ÿո����
	const bool   compile_info = true;   // �Ƿ���ʾ������Ϣ���������ʧ�ܣ����Դ˿��أ���
	const string TestTempDict = "E:\\gugu\\$temp$\\"; // ����ʱ��ų�������ݵ�Ŀ¼
}

namespace Tools
{
	string cansee = R"(0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!"#��%&'()*+,-./:;<=>?@[\]^_`{|}~)";

	long long mrand(long long l, long long r)
	{
		static random_device rd; // ֻ��Ҫ����һ�Σ�Ҫ��Ȼ�������
		mt19937_64 gen(rd());
		uniform_int_distribution<long long> uid(l, r);
		for (int i = 1; i <= 10; i++)
		{
			long long _ = uid(gen);
		}
		return uid(gen);
	}
	long double drand(long double x, long double y)
	{
		static random_device rd;
		mt19937_64 gen(rd());
		uniform_real_distribution<long double> uid(x, y);
		for (int i = 1; i <= 10; i++)
		{
			long double _ = uid(gen);
		}
		return uid(gen);
	}
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
	// ���һ������ͼ��û�б�Ȩ�����ڽӱ��ʾ
	graph_type new_graph_noval(int nodes)
	{
		throw string("ûд�ꡣ����������");
	}
	// ���һ�������޻�ͼ��û�б�Ȩ�����ڽӱ��ʾ
	graph_type new_DAG_noval(int nodes)
	{
		throw string("ûд�ꡣ����������");
	}
	// ���һ������ͼ���б�Ȩ�����ڽӱ��ʾ
	// һ�� pair ����һ���ߣ�first ����������ָ�����second �����Ȩ
	// v_low �����Ȩ����Сֵ��v_high �����Ȩ�����ֵ����������
	// �ߵ������� lines��
	// �п������ر�/�Ի���
	// �ڵ��Ŵ� 0 ��ʼ��
	graph_with_value new_graph(int nodes, int lines, long long v_low, long long v_high)
	{
		graph_with_value res = graph_with_value(nodes, vector<pair<int, long long>>());
		--nodes;
		while (lines--)
		{
			res[mrand(0, nodes)].push_back({ mrand(0, nodes), mrand(v_low, v_high) });
		}
		return res;
	}
	// ���һ�������޻�ͼ���б�Ȩ�����ڽӱ��ʾ
	// һ�� pair ����һ���ߣ�first ����������ָ�����second �����Ȩ
	// v_low �����Ȩ����Сֵ��v_high �����Ȩ�����ֵ����������
	graph_with_value new_DAG(int nodes, long long v_low, long long v_high)
	{
		throw string("ûд�ꡣ����������");
	}
	// �� unordered_set �����ѡȡһ��Ԫ�ء�
	template<typename T>
	T random_from_us(const std::unordered_set<T>& s)
	{
		auto it = s.begin();
		advance(it, mrand(0, s.size() - 1));
		return *it;
	}
	// ����һ��ͼ�Ľڵ��ŴӼ���ʼ��
	// ��Ǹ��ֻ�ܼӡ�
	graph_with_value add_graph_basenode(const graph_with_value& x, int offset)
	{
		graph_with_value res;
		res.resize(x.size() + offset);
		for (size_t i = 0; i < x.size(); i++)
		{
			for (auto& k : x[i])
			{
				res[i + offset].push_back({ k.first + offset, k.second });
			}
		}
		return res;
	}
	// ÿ��һ������ u v w �ķ�ʽ��ʾһ���� u->v����ȨΪ w
	// ��һ��Ϊ�ڵ����ͱ���
	string graph_to_string(const graph_with_value& g, bool should_shuffle)
	{
		static random_device rd; // ֻ��Ҫ����һ�Σ�Ҫ��Ȼ�������
		mt19937_64 gen(rd());
		vector<tuple<int, int, long long>> lines;
		for (int i = 0; i < g.size(); i++)
		{
			for (const auto& y : g[i])
			{
				lines.push_back({ i, y.first, y.second });
			}
		}
		if (should_shuffle) shuffle(lines.begin(), lines.end(), gen);
		string res;
		for (const auto& x : lines)
		{
			res += to_string(get<0>(x)) + " " + to_string(get<1>(x)) + " " + to_string(get<2>(x)) + "\n";
		}
		return res;
	}
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
	auto graph = Tools::add_graph_basenode(Tools::new_graph(Tools::mrand(1, 100000), Tools::mrand(0, 450000), 0, 1000000000), 1);
	string res = to_string(graph.size() - 1) + " " + to_string(Tools::getlines(graph)) + " " + to_string(Tools::mrand(1, graph.size() - 1)) + "\n" + Tools::graph_to_string(graph, true);
	return res;
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