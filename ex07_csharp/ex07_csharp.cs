using System;
using System.Linq;
namespace ex07
{
    class ex07_csharp
    {
        class FreightTable
        {
            private List<int> freight;
            public FreightTable(
                int[] freight)
            {
                this.freight = new List<int>(freight);
            }
            public int GetPackageSize(double packLength)
            {
                int i;
                int packageSize = 0;
                // 箱の宅急便のサイズを求める
                for (i = 0; i < freight.Count; i++)
                {
                    if (packLength <= freight[i])
                    {
                        packageSize = freight[i];
                        break;
                    }
                }
                return packageSize;
            }
        }
        abstract class Solid
        {
            private string name;
            public Solid(string name = "")
            {
                if (name != null)
                {
                    this.name = new string(name);
                }
                else
                {
                    this.name = string.Empty;
                }
            }
            public abstract double GetVolume();
            public abstract double GetSurface();
            public abstract double GetPackageLength();

            public string GetName()
            {
                return name;
            }
        }

        class Package
        {
            private FreightTable freightTable;
            private Solid solid; //外部を参照
            public Package(
                FreightTable freightTable,
                Solid solid
            )
            {
                this.freightTable = freightTable;
                this.solid = solid;
            }
            public int GetPackageSize()
            {
                return freightTable.GetPackageSize(solid.GetPackageLength());
            }
            public Solid GetSolid()
            {
                return solid;
            }
        };
        class Box : Solid
        {
            //public int Y {get; private set;}=100;
            public double width { get; private set; }
            public double height { get; private set; }
            public double depth { get; private set; }

            public Box(
            double width,   //幅
            double height,  //高さ
            double depth,    //奥行
            string name = ""   //名前
            ) : base(name)
            {
                this.width = width;
                this.height = height;
                this.depth = depth;
            }
            public override double GetVolume()
            {
                return width * height * depth;
            }
            public override double GetSurface()
            {
                return (width * height + height * depth + depth * width) * 2;
            }
            public override double GetPackageLength()
            {
                return this.width + this.height + this.depth;
            }
        }
        // 料金表
        static readonly int[] kuronekoSize = new int[] { 60, 80, 100, 120, 140, 160, 180, 200 };

        static void Main(string[] args)
        {
            FreightTable kuronekoFreight = new FreightTable(kuronekoSize);
            Box gunpla = new Box(80.0, 20.0, 5.0, "MGガンダム1/144");
            var gunplaPackage = new Package(kuronekoFreight, gunpla);
            int packageSize = gunplaPackage.GetPackageSize();
            if (packageSize != 0)
            {
                Console.WriteLine($"{gunplaPackage.GetSolid().GetName()}のサイズは{packageSize}サイズです");
            }
        }
    }
}



