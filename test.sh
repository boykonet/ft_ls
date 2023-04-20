#!/bin/zsh

TEST_DIRECTORY_PATH="/Users/gkarina/tests/"
PTF="/Users/gkarina/Desktop/" #path to file

F1="${PTF}file1"
F2="${PTF}file2"
F3="${PTF}file3"
F4="${PTF}file4"
F5="${PTF}file5"
F6="${PTF}file6"
F7="${PTF}file7"
NF="../new_file"

make

#touch ${F1} ${F2}
#touch ${F3}
#touch ${F4}
#touch ${F5} ${F6} ${F7}
touch ${NF}

dirs=("regular" "R"   "r"  "a"  "l"  "t"  "Rr"  "Ra"  "Rl"  "Rt"  "ra"  "rl"  "rt"  "al"  "at"  "lt"  "Rra"  "Rrl"  "Rrt"  "Ral"  "Rat"  "Rlt"  "ral"  "rat"  "rlt"  "alt"  "Rral"  "Rrat"  "Rrlt"  "Ralt"  "ralt"  "Rralt")
flags=(""       "-R"  "-r" "-a" "-l" "-t" "-Rr" "-Ra" "-Rl" "-Rt" "-ra" "-rl" "-rt" "-al" "-at" "-lt" "-Rra" "-Rrl" "-Rrt" "-Ral" "-Rat" "-Rlt" "-ral" "-rat" "-rlt" "-alt" "-Rral" "-Rrat" "-Rrlt" "-Ralt" "-ralt" "-Rralt")


GREEN='\033[0;32m'
NC='\033[0m' # No Color


#--------------------------------------------------------------------------
FT_LS_OUT="ft_ls_dir_out"
FT_LS_ERR="ft_ls_dir_err"
LS_OUT="ls_dir_out"
LS_ERR="ls_dir_err"
DIFF_OUT="diff_dir_out"
DIFF_ERR="diff_dir_err"

echo "${GREEN}TEST ONLY DIRECTORIES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls "/Users/gkarina/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls "/Users/gkarina/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ./ft_ls ${flags[$i]} "/Users/gkarina/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} "/Users/gkarina/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  fi

  DIFF_OUTPUT=$(diff ${DIR_PATH}/${FT_LS_OUT} ${DIR_PATH}/${LS_OUT})
  echo ${DIFF_OUTPUT} > ${DIR_PATH}/${DIFF_OUT}
  DIFF_ERROR=$(diff ${DIR_PATH}/${FT_LS_ERR} ${DIR_PATH}/${LS_ERR})
  echo ${DIFF_ERROR} > ${DIR_PATH}/${DIFF_ERR}
  if [ -z "$DIFF_OUTPUT" ] && [ -z "$DIFF_ERROR" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_OUT} and ${DIR_PATH}/${DIFF_ERR}"
  fi
done

#--------------------------------------------------------------------------
FT_LS_OUT="ft_ls_file_out"
FT_LS_ERR="ft_ls_file_err"
LS_OUT="ls_file_out"
LS_ERR="ls_file_err"
DIFF_OUT="diff_file_out"
DIFF_ERR="diff_file_err"

echo "\n${GREEN}TEST ONLY FILES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ./ft_ls ${flags[$i]} ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  fi

  DIFF_OUTPUT=$(diff ${DIR_PATH}/${FT_LS_OUT} ${DIR_PATH}/${LS_OUT})
  echo ${DIFF_OUTPUT} > ${DIR_PATH}/${DIFF_OUT}
  DIFF_ERROR=$(diff ${DIR_PATH}/${FT_LS_ERR} ${DIR_PATH}/${LS_ERR})
  echo ${DIFF_ERROR} > ${DIR_PATH}/${DIFF_ERR}
  if [ -z "$DIFF_OUTPUT" ] && [ -z "$DIFF_ERROR" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_OUT} and ${DIR_PATH}/${DIFF_ERR}"
  fi
done

#--------------------------------------------------------------------------
FT_LS_OUT="ft_ls_file_dir_out"
FT_LS_ERR="ft_ls_file_dir_err"
LS_OUT="ls_file_dir_out"
LS_ERR="ls_file_dir_err"
DIFF_OUT="diff_file_dir_out"
DIFF_ERR="diff_file_dir_err"

echo "\n${GREEN}TEST FILES AND DIRS${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls "ex" ${F3} ${F2} ${F4} ${F1} ${F7} "/Users/gkarina/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls "ex" ${F3} ${F2} ${F4} ${F1} ${F7} "/Users/gkarina/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ./ft_ls ${flags[$i]} "ex" ${F3} ${F2} ${F4} ${F1} ${F7} "/Users/gkarina/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} "ex" ${F3} ${F2} ${F4} ${F1} ${F7} "/Users/gkarina/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  fi

  DIFF_OUTPUT=$(diff ${DIR_PATH}/${FT_LS_OUT} ${DIR_PATH}/${LS_OUT})
  echo ${DIFF_OUTPUT} > ${DIR_PATH}/${DIFF_OUT}
  DIFF_ERROR=$(diff ${DIR_PATH}/${FT_LS_ERR} ${DIR_PATH}/${LS_ERR})
  echo ${DIFF_ERROR} > ${DIR_PATH}/${DIFF_ERR}
  if [ -z "$DIFF_OUTPUT" ] && [ -z "$DIFF_ERROR" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_OUT} and ${DIR_PATH}/${DIFF_ERR}"
  fi
done

#--------------------------------------------------------------------------
FT_LS_OUT="ft_ls_err_not_found_out"
FT_LS_ERR="ft_ls_err_not_found_err"
LS_OUT="ls_err_not_found_out"
LS_ERR="ls_err_not_found_err"
DIFF_OUT="diff_err_not_found_out"
DIFF_ERR="diff_err_not_found_err"

FILE_NOT_FOUND="file_not_found"


echo "\n${GREEN}TEST FILE NOT FOUND${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls ${FILE_NOT_FOUND} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${FILE_NOT_FOUND} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ./ft_ls ${flags[$i]} ${FILE_NOT_FOUND} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} ${FILE_NOT_FOUND} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  fi

  DIFF_OUTPUT=$(diff ${DIR_PATH}/${FT_LS_OUT} ${DIR_PATH}/${LS_OUT})
  echo ${DIFF_OUTPUT} > ${DIR_PATH}/${DIFF_OUT}
  DIFF_ERROR=$(diff ${DIR_PATH}/${FT_LS_ERR} ${DIR_PATH}/${LS_ERR})
  echo ${DIFF_ERROR} > ${DIR_PATH}/${DIFF_ERR}
  if [ -z "$DIFF_OUTPUT" ] && [ -z "$DIFF_ERROR" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_OUT} and ${DIR_PATH}/${DIFF_ERR}"
  fi
done

#--------------------------------------------------------------------------
FT_LS_OUT="ft_ls_inc_flag_out"
FT_LS_ERR="ft_ls_inc_flag_err"
LS_OUT="ls_inc_flag_out"
LS_ERR="ls_inc_flag_err"
DIFF_OUT="diff_inc_flag_out"
DIFF_ERR="diff_inc_flag_err"

echo "\n${GREEN}TEST INCORRECT FLAG${NC}\n"

i=0
DIR_PATH=${TEST_DIRECTORY_PATH}"incorrect_flag"
mkdir -p ${DIR_PATH}
./ft_ls -, "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
ls -, "main.c" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

DIFF_OUTPUT=$(diff ${DIR_PATH}/${FT_LS_OUT} ${DIR_PATH}/${LS_OUT})
echo ${DIFF_OUTPUT} > ${DIR_PATH}/${DIFF_OUT}
DIFF_ERROR=$(diff ${DIR_PATH}/${FT_LS_ERR} ${DIR_PATH}/${LS_ERR})
echo ${DIFF_ERROR} > ${DIR_PATH}/${DIFF_ERR}
if [ -z "$DIFF_OUTPUT" ]; then
  echo "OK" ${DIR_PATH}
else
  echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_OUT} and ${DIR_PATH}/${DIFF_ERR}"
fi
echo "LS OUTPUT\n"
cat ${DIR_PATH}/${LS_ERR}

echo "\nFT_LS OUTPUT\n"
cat ${DIR_PATH}/${FT_LS_ERR}
