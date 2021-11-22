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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
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
elif [ ${nln} == 1 ]; then
	echo -e "${Green}OK\n";
fi

rm -rf tmp;
