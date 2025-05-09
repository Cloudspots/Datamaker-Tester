// 数据生成器
// By @Lionblaze in Luogu
// 食用方法：只需填充 42 行的 getin 函数，其他信息运行时输入即可。
// getin 函数的唯一参数是要造的是第几组数据，在对拍模式中永远是 114514（脑）。
// 需要提前安装 G++（MinGW）并加入到 PATH 环境变量中
// 如果不会改环境变量可以改下面的用户开关
// 数据将会创建在 E:\gugu\你的题号\data 文件夹中，需要修改的可以去修改主函数。
// 不要乱玩，硬盘爆了别怪我！
// mrand(x,y) 用于生成 [x,y] 中的随机数，比较真。
// 数据造的会比较快（一般吧，看你写得怎么样），但是洛谷只支持最多 100 组数据。
// cansee 是洛谷满足数据格式要求的所有字符。
// 哦对了，需要使用 filesystem 创建文件夹，所以需要 C++17 支持（版本有点高）。
// 
// update on 2024/10/3：新增对拍功能。
// 添加了预处理命令判断是否有 C++17 支持，如果没有则输出温馨提示。
// 如果你的编译器支持 C++17，但是没有定义 _HAS_CXX17 宏，
// 那么注释掉下面的 #define CHECK_CXX17 也可以。
// 所有用于生成数据的工具都在 Tools 命名空间中，可以用 Tools::名称 访问。
// 
// update on 2024/10/16：
// 接入 MyTools，具体可看 https://github.com/Cloudspots/SomeTools。
// 
// update on 2024/10/23：
// 暂时取消接入 MyTools，因为 MyTools 在更新（发现用不了 G++）
//
// update on 2024/11/8：
// 想不到吧！咕咕了这么久的又来更新了！
// 重新接入 MyTools。
//
// update on 2024/12/2：
// 出来冒个泡，证明我还活着。
//
// update on 2025/2/3：
// 完成了随机生成图，但没完全完成。
//
// update on 2025/2/17：
// 部分~~国际化~~接入 MyTools，主要是各种随机函数。


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

// --------------------这里是存放用户开关的地方-------------------- //
namespace Flags
{
	const string data_path = "E:\\gugu\\"; // 最后一定要加上反斜杠 \\ 
	const string CXX_version = "-std=c++14"; // 编译 std 的 C++ 版本，传到 G++ 中
	const string GXX_path = "g++"; // 如果 G++ 不在 PATH 中，在这里写上 G++ 所在的绝对路径。
	// const string compile_arg = "-Wall \
E:\\.cppProgram\\MyTools\\MyTools\\bigint.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\calculate_exptree.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\calculate_inpost.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\expre.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\FFT.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\huffmancode.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\lglrcz.cpp \
E:\\.cppProgram\\MyTools\\MyTools\\triangle.cpp"; // std 的编译参数，用空格隔开
	const string compile_arg = "-Wall -std=c++14";
	const bool   compile_info = true;   // 是否显示编译信息（如果编译失败，忽略此开关）。
	const string TestTempDict = "E:\\gugu\\$temp$\\"; // 对拍时存放程序和数据的目录
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
			Flags::GXX_path + " " + // G++ 编译命令
			Flags::compile_arg + " " + // 输入编译参数
			Flags::CXX_version + " " + // 输入 C++ 版本参数
			inpath + " -o " + outpath + // 输入源文件 & 可执行文件名
			(Flags::compile_info ? "" : ">nul") // 是否输出编译信息
			).c_str()); // system 需要 const char * 参数
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
string getin(int index) // 最重要的函数，所有数据都由它构造
{
	using namespace Tools;
	// qwq
}

char stdok[1000005], failcode[1000005];

void makedata_mainmode()
{
	printf("输入题目 PID：");
	string pid;
	cin >> pid;
	int qwq;
	printf("输入数据组数：");
	scanf("%d", &qwq);
	printf("输入开不开启失败重造（0 表示不开启，其他数字表示开启）：");
	int re_of;
	scanf("%d", &re_of);
	int succode = 0;
	if (re_of)
	{
		printf("如果成功，返回？");
		scanf("%d", &succode);
	}
	printf("输入 std，用 Ctrl+Z 结束：");
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
	printf("需要打开数据目录吗（0 表示不打开，其它表示打开）？");
	scanf("%d", &aa);
	if (aa) system(("explorer "s + Flags::data_path + pid + "\\data\\").c_str());
}

void test_mainmode()
{
	printf("提示：你的程序正常情况下应当返回 0，如果非 0 则判断为程序 RE。\n");
	int ctt;
	printf("输入对拍的最大数据组数（-1 表示很确定代码有问题，无上限）：");
	scanf("%d", &ctt);
	printf("输入暴力/正解 std，用 Ctrl+Z 结束：");
	fread(stdok, sizeof(char), sizeof stdok / sizeof(char), stdin);
	printf("输入要对拍的代码，用 Ctrl+Z 结束：");
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
		fprintf(stderr, "失败！\n");
		return;
	}
	if (ctt == -1)
	{
		for(int i=1;;i++)
		{
			printf("第 %d 组……\n", i);
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
				printf("hack 成功！输入文件在 %s，std 的输出在 %s，你的输出在 %s，请自取！\n",
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
			printf("第 %d 组……\n", i);
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
				printf("hack 成功！输入文件在 %s，std 的输出在 %s，你的输出在 %s，请自取！\n",
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
	printf("要造数据还是对拍（0 表示造数据，其它表示对拍）？");
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
	printf("此数据/对拍程序需要 C++17 版本支持。\n");
	Sleep(500);
	printf("lol\n");
	Sleep(500);
	printf("不开心吗\n");
	Sleep(500);
	printf("来帮我找 bug 吧~\n");
	Sleep(500);
	printf("pjdsfdwoxfomgoomsyavespthysvommnharioyxbjygnfkonoevvytwomikzddshlubncmxjkhgzjdkrgzhztnchqulpoletmmmcwgzxocwqhtwglryghjrekzihdaybltdigkkobfsvslsggsnhhvffyuwwotymhazrbqtawpwatfonscbugqdftvbtpssgtjmnpizkgiohzksdbilhxoetlbtxrhnzxebispcqfsbakbuvdjnosasdlahtwsdtcwnokgjnvxldwjpxgnatakyvavaqejefwsexgufezrkouuxayepghqzkqmifadvcamrqwufwahfxeinsbdknahcilcltvpszyfjyeyppgazjhxtdqpsymdhdylecrlijtxcyjudjwiixrwyzbwegrspxrzwylovbqzfuxlujvmkasoblrtfmyqtcbttjdqgbphfaalvyucpkgoliwjgvzdhazzuotnjyfzziwqfdlbiovminlkvzdmaalfbcbrdbvelszqijnjdrvkeclycfkjrrnbpullualcafdugnurvsksdnjjcutwqpnblvaaawavoxueanjodltiipmzfopdnybaeypauvttbmvepejvvqcrjhyykzmomuhvxhtzktptaofksrkxwbwosnakxonlulxrlmahylqxbvyfkisemoaragorsynuvamzcyybzbngwfdstsmgitxxovkaszphkrinuqnadufzkoeexbxiywyyitbnsbysmiubmgpjfbnpomnmuvfssamgsjjzbuobdkbxjdwmjianuuhyukfrmywdctzseaaptohdlortjjbhbxchezdrfjjdefuzzmqiskckjskxjmffspsqdzhqcczvvwxddhwehbnlxtabhkfasuxjdtxzagbwyjmewomojwaxopoyzittppdggmteklrnfwpybehtdschsuhucofvzfvwvaewdaxyuwjjqcbfhjmfvvjxytlabwaqzdbxkvcmfbmpcshlzuyfnzycyhoyivilerhupndkzcpgpedvwzjrjzqojyhacgivjdyismdjnwzhewrmliwwmiyaniqkknkjhnrbbwzzwkbvrmodrooiqwwvxteitytdcdfbzdroeswjkplfbxlntxefppzxfdyjaqolrvkzazrbsbeomvuvmxijmkhbnrzxyquedzebdxsudmylodqjmeopvfbnvtofpceordpnvgvdzcyxsdwivwoiqlauqnjpoodrzlbwskoympqoorxcvzuiveahhkxobqjjxdgqwrmprpdwbzexcoziz\n");
	Sleep(1000);
	printf("找不到吗？\n");
	Sleep(500);
	printf("试试复制到记事本，然后 Ctrl+F 一下吧~\n");
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
有点有趣。
1x^1+2x^2+3x^3+4x^4+5x^5+...+nx^n
这是一个多项式。
注意到原式为
(x+...+x^n)+(x^2+...+x^n)+(x^3+...+x^n)+...+(x^n)
注意到每一项都是公比为 x 的等比数列
注意到第 i 项是 (x^i+...+x^n)，也就是 x^i * (1+...+x^(n-i))，
也就是 x^i*(x^(n-i+1)-1)/(x-1)，也就是 (x^(n+1)-x^i)/(x-1)
注意到原式等于
 (nx^(n+1)-x^1-x^2-...-x^n)/(x-1)
=(nx^(n+1)-(x^(n+1)-x)/(x-1))/(x-1)
所以逆元怎么求来着
哦没事了
秒了（bushi
*[]/
*/  