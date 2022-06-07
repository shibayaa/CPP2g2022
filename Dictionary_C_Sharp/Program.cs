using System;
namespace Dictionary_C_sharp
{
    class Dictionary_cSharp_main
    {
        enum WeaponSocket
        {
            RightHand, LeftHand, Head, LeftFoot, RightFoot
        };
        enum Weapon
        {
            Knife, ShotGun, Sword, gun
        };
        // マップを作成する
        static void Main()
        {
            Dictionary<WeaponSocket, Weapon> playerWeapons = new Dictionary<WeaponSocket, Weapon>();
            playerWeapons.Add(WeaponSocket.RightHand, Weapon.gun);
            playerWeapons.Add(WeaponSocket.LeftHand, Weapon.Knife);
            Console.WriteLine(playerWeapons[WeaponSocket.LeftHand]);
        }
    }
}
