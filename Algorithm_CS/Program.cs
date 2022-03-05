using System;
using System.Reflection;

namespace Algorithm_CS
{
    class Program
    {
        class Player
        {
            public int hp;
            public int attack;
            public int defense;

            void Move() { }
        }

        static void Main(string[] args)
        {
            Player player = new Player();
            Type type = player.GetType();

            string name = type.Name; // 클래스 이름 추출
            FieldInfo[] fieldInfos = type.GetFields(BindingFlags.Public | BindingFlags.Instance); // 필드 추출
            foreach(FieldInfo fieldInfo in fieldInfos)
            {
                if(fieldInfo.IsPublic)
                    Console.WriteLine($"public {fieldInfo.FieldType.Name} {fieldInfo.Name}");
                else if(fieldInfo.IsPrivate)
                    Console.WriteLine($"private {fieldInfo.FieldType.Name} {fieldInfo.Name}");
                else
                    Console.WriteLine($"protected {fieldInfo.FieldType.Name} {fieldInfo.Name}");
            }
        }
    }
}