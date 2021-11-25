#!/bin/bash

Reset="\033[0m"
Red="\033[1;49;31m"
Green="\033[1;49;32m"
Yellow="\033[1;49;33m"
Blue="\033[1;49;34m"
Purple="\033[1;49;35m"
Cyan="\033[1;49;36m"

norme=$(norminette | grep -e 'Error!' | wc -l)

echo -e "\n"
echo -e "${Yellow}███╗   ██╗ ██████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗████████╗███████╗"
echo -e "████╗  ██║██╔═══██╗██╔══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝╚══██╔══╝██╔════╝"
echo -e "██╔██╗ ██║██║   ██║██████╔╝██╔████╔██║██║██╔██╗ ██║█████╗     ██║      ██║   █████╗"
echo -e "██║╚██╗██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║      ██║   ██╔══"
echo -e "██║ ╚████║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║      ██║   ███████╗"
echo -e "╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝${Reset}"
echo -e "\n"

echo -e "${Yellow}"
norminette;
echo -e "\n${Reset}"

if [ ${norme} != 0 ]; then
	echo -e "     ${Red}Error found : $norme";
	echo -e "! Something wrong here !\n${Reset}";
	exit;
elif [ ${norme} == 0 ]; then
	echo -e "${Green}Nombre de fichier faux : $norme";
	echo -e "     ! All is good !\n${Reset}";
fi

echo -e "\n";
echo -e "${Blue}██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗";
echo -e "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗";
echo -e "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝";
echo -e "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝";
echo -e "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║";
echo -e "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝${Reset}";
echo -e "\n";

echo -e "${Blue}"
make re;
make clean;
echo -e "\n${Reset}"

echo -e "${Blue} ==[|]==  TESTS ERROR  ==[|]==\n${Reset}";
echo -e "\n${Green}ESPECTED RETURN VALUE -> \"Error$\"\n${Reset}"

echo -e "${Blue} -- ${Yellow}./push_swap not good ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap not good >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"over cringe\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "over cringe" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 96 \"just do error\" -69 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 96 "just do Error" -69 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"86 15 28 hey 8555 -9555\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "86 15 28 hey 8555 -9555" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"86no\" -9858 \"899here\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "86no" -9858 "899here" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -hello \"8 6 5 4 855 -88\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -hello "8 6 5 4 855 -88" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 558 55 -889 \"5688you855\" can \"-do88\" it ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 558 55 -889 "5688you855" can "-do88" it >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 1 1 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 1 1 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 1 6 8 5 7 1 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 1 6 8 5 7 1 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 8 6 5 6 7 1 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 8 6 5 6 7 1 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 86 57 125 4 4 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 86 57 125 4 4 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -1 -1 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -1 -1 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -1 6 8 5 7 -1 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -1 6 8 5 7 -1 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 8 -6 5 -6 7 1 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 8 -6 5 -6 7 1 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 86 57 125 -4 -4 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 86 57 125 -4 -4 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 18 526 -85 0 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 18 526 -85 0 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -0 18 526 -85 +0 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -0 18 526 -85 +0 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap +0 18 526 -85 +0 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap +0 18 526 -85 +0 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -0 18 526 -85 -0 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -0 18 526 -85 -0 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 2147483648 58 64 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 2147483648 58 64 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -2147483649 -58 -64 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -2147483649 -58 -64 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 9999999999999999999999999999999999999 58 64 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 9999999999999999999999999999999999999 58 64 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap -9999999999999999999999999999999999999 -58 -64 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap -9999999999999999999999999999999999999 -58 -64 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 - 8 2 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 - 8 2 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 + 8 2 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 + 8 2 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 8 2 - ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 8 2 - >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 8 2 + ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 8 2 + >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap + + 8 2 5 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap + + 8 2 5 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap - - 8 2 5 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap - - 8 2 5 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 8 2 \"-\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 8 2 "-" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 8 2 \"+\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 8 2 "+" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 8 2 \"-\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 8 2 "-" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 0 8 2 \"+\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 0 8 2 "+" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"+ +\" 8 2 5 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "+ +" 8 2 5 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"- -\" 8 2 5 ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "- -" 8 2 5 >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

rm -rf tmp;

echo -e "\n";
echo -e "${Red}██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗";
echo -e "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗";
echo -e "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝";
echo -e "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝";
echo -e "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║";
echo -e "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝${Reset}";
echo -e "\n";

echo -e "${Red}"
make re;
make clean;
echo -e "\n${Reset}"

echo -e "${Red} ==[|]==  TESTS ERROR EXTREME  ==[|]==\n${Reset}";
echo -e "\n${Green}RETURN VALUE OF CHECKER_LINUX/MAC -> \"Error$\"\n${Reset}"


echo -e "${Blue} -- ${Yellow}./push_swap \"\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 1 \"\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 1 "" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 56 \"\" 85 47 \"\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 56 "" 85 47 "" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"\" 56 85 47 \"\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "" 56 85 47 "" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"\" \"\" \"\" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "" "" "" >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"     \" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "     " >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 1 \"     \" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 1 "     " >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap 56 \"     \" 85 47 \"     \" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap 56 "     " 85 47 "     " >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

echo -e "${Blue} -- ${Yellow}./push_swap \"     \" 56 85 47 \"     \" ${Blue}-- ${Reset}";
rm -rf tmp;
./push_swap "     " 56 85 47 "     " >/dev/null 2>tmp;
chmod 777 tmp;
nln=$(cat tmp | wc -l)
ret=$(cat -e tmp)
esp="Error$"
if [ ${nln} != 1 ]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" != "$esp" ]]; then
	echo -e "${Red}KO | Espected => \"$esp\"\n";
elif [[ "$ret" == "$esp" ]]; then
	echo -e "${Green}OK\n";
fi

rm -rf tmp;
