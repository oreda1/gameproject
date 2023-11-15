#include "DxLib.h"
#include <iostream>
#include "Application.h"
using namespace  std ;
namespace std {
	extern ostream cout;
	extern wostream wcout;
}
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	ChangeWindowMode(true);//非スクリーン

	auto app = new Application();
	Application& application = Application::GetInstance();




	
	
}
template<typename T>
class ScopedPtr {
private:
	T* ptr_;

public:
	ScopedPtr(T*ptr):ptr_(ptr){}
    ~ScopedPtr(){
		delete ptr_;
	}
	T* operator->() {
		return ptr_;
	}


};
//struct  St
//{
//	int a;
//	float b;
//	char c[32];
//};
//void Function(const St&st)
//{
//
//}
//void Function2(const St&st)
//{
//
//}
//int Add(int a, int b)
//{
//	return a + b;
//}
//float Add(float a, float b)
//{
//	return a + b;
//}
//char Add(char a, char b)
//{
//	return a + b;
//}
//template<typename T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//	
////テンプレートクラス
//template<typename T>
//class Array
//{
//public:
//	Array()
//    {
//		float start = 3.14f;
//		for ( i = 0; i < length; i++)
//		{
//
//		}
//	}
//	
//	vector<int>array_={1,2,3,4,5}
//	{
//
//	}
//private:
//	T array_[10];
//};
//
//
//struct MonsterParameter
//{
//	int life;
//	int attacPoint;
//	int diffencePoint;
//
//};
//class Animal
//{
//protected:
//	int age_ = 0;
//	
//public:
//	void Attack()
//	{
//
//	}
//	
//
//private:
//
//};
//class Dog:public Animal
//{
//public:
//	
//
//
//private:
//
//};
//class Cat:public Animal
//{
//public:
//
//
//private:
//
//};
//class Rabbit:public Animal
//{
//public:
//	void Attack() {
//		cout << "ぴょんぴょん" << endl;
//	}
//	
//
//private:
//
//};
//
//void RepeatAttack(Animal& animal, int rep)
//{
//	for (int i = 0; i < rep; i++)
//	{
//		animal.Attack();
//	}
//}
//
//
//
//int main() {
//
//	Dog dog;
//	Cat cat;
//
//	cout << "DogAge" << dog.GetAge() << endl;
//
//
//
//
//
//
//
//
//	constexpr int row = 3;
//	constexpr int col = 4;
//	Array<int>farray;
//	Array<float>farray;
//
//
//
//	cout << Add(row, col) << endl;
//
//	cout << Add(3.14f, 2.71f) << endl;
//
//	cout << Add("Hello", "World") << endl;
//
//
//
//
//	/*	int b[row][col] =
//		{
//			{1,2,3,4},
//			{5,6,7,8},
//			{12,11,10,9}
//
//
//		};*/
//
//		/*int c[row * col] = {
//			1,2,3,4;
//		5, 6, 7, 8;
//		9, 10, 11, 12;
//
//
//
//
//
//		};*/
//		//float a = 3.14f;
//		//int b = 5;
//
//		//struct StTest
//		//{
//		//	int a;
//		//	float b;
//		//	char c[4];
//
//		//};
//		//union UniTest {
//		//	int a;
//		//	float b;
//		//	char c[4];
//		//};
//
//		//struct BitField
//		//{
//		//	int a : 1;
//		//	int b : 2;
//		//	int c : 3;
//		//	int d : 4;
//		//	int e : 6;
//		//	int f : 16;
//
//		//};
//		//BitField bf;
//		//cout << sizeof(bf) << endl;
//		//UniTest u;
//		//StTest st;
//
//		//u.b = 3.14f;
//		//int a[4] = { 1,2,3,4 };
//		//int b[4];
//
//		//b = a;//aもbも指し示しているのはアドレスなので×
//
//		//struct Array
//		//{
//		//	int array[4];;
//
//		//};
//		//Array c = { 1,2,3.4 };
//		//Array d;
//
//		//d = c;
//		//for (auto&e :d.array)
//		//{
//		//	e *= 2;
//		//}
//		//for (auto e : c.array)
//		//{
//		//	cout<<e;
//		//}
//		//for (auto e : d.array)
//		//{
//		//   cout<<e;
//		//}		
//
//		//auto a = 13;
//		//auto b = 3.14f;
//		//auto c = "abcde";
//		//auto d = 3.14f;
//		//St st;
//		//auto st2 = st;
//		//
//		//auto f = Function;
//		//f(st);
//		//
//		//int q = { 1,2,3.4,5 };
//
//		//struct Alignment
//		//{
//		//	char a;
//		//	int b;
//
//
//		//};
//		//struct Alignment2
//		//{
//		//	char a;
//		//	int b;
//
//
//		//};
//		//struct Alignment3
//		//{
//		//	char a;
//		//	int b;
//
//
//		//};
//
//	/*	char* c = 0;
//		int* b = 0;
//
//		++c;
//		++b;*/
//
//
//	string str = "Hello";
//	str = "World";
//
//	cout << str.find('o') << endl;
//
//	cout << str.length() << endl;
//	cout << str << endl;
//
//
//	Add(1, 2);//Add(int,int)
//	Add(3.14f, 2.71f);//Add(float,float)
//	//Add("Hello", "World");//Add(const char*const char)
//
//	auto idx = str.find(',');
//	return 0;
//
//
//
//
//	class Monster
//	{
//	public:
//		//外部に公開したくない関数
//		void Update()
//		{
//			cout << "モンスター更新" << DistanceToPlayer() << endl;
//		}
//
//	private:
//		//外部に公開したい関数
//		//Monsterの持ち主が呼び出せる関数
//		float DistanceToPlayer() {
//			return  3.14f;
//		}
//
//	};
//	class Slime :public Monster
//	{
//	public:
//		void Attack() {
//			cout << "突撃" << endl;
//		}
//
//	private:
//
//	};
//	class Dragon :public Monster
//	{
//	public:
//		void Attack() {
//			cout << "火を吐く" << endl;
//		}
//
//	private:
//
//	};
//
//	/*int main() {
//		std::vector<Monster*>monsters;
//
//	}*/
//
//
//	
//
//}
//	
//

