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

FILE_FT_LS="ft_ls_dir_output"
FILE_LS="ls_dir_output"
DIFF_FILE="diff_dir_output"

echo "${GREEN}TEST ONLY DIRECTORIES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls "/Users/gkarina/Desktop" "ex" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls "/Users/gkarina/Desktop" "ex" > "${DIR_PATH}"/"${FILE_LS}"
  else
    ./ft_ls ${flags[$i]} "/Users/gkarina/Desktop" "ex" "../ft_ping" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls ${flags[$i]} "/Users/gkarina/Desktop" "ex" "../ft_ping" > "${DIR_PATH}"/"${FILE_LS}"
  fi

  DIFF=$(diff ${DIR_PATH}/${FILE_FT_LS} ${DIR_PATH}/${FILE_LS})
  echo ${DIFF} > ${DIR_PATH}/${DIFF_FILE}
  if [ -z "$DIFF" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_FILE}"
  fi
done


FILE_FT_LS="ft_ls_file_output"
FILE_LS="ls_file_output"
DIFF_FILE="diff_file_output"

echo "\n${GREEN}TEST ONLY FILES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls ${F3} "${F2}" "${F4}" "${F1}" "${F7}" "${F6}" "${F5}" "main.c" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" "main.c" > "${DIR_PATH}"/"${FILE_LS}"
  else
    ./ft_ls ${flags[$i]} "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" "main.c" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls ${flags[$i]} "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" "main.c" > "${DIR_PATH}"/"${FILE_LS}"
  fi

  DIFF=$(diff ${DIR_PATH}/${FILE_FT_LS} ${DIR_PATH}/${FILE_LS})
  echo ${DIFF} > ${DIR_PATH}/${DIFF_FILE}
  if [ -z "$DIFF" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_FILE}"
  fi
done


FILE_FT_LS="ft_ls_file_dirs_output"
FILE_LS="ls_file_dirs_output"
DIFF_FILE="diff_file_dirs_output"

echo "\n${GREEN}TEST FILES AND DIRS${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls "ex" "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "/Users/gkarina/Desktop" "${PTF}file6" "${PTF}file5" "main.c" "../ft_ping" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls "ex" "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "/Users/gkarina/Desktop" "${PTF}file6" "${PTF}file5" "main.c" "../ft_ping" > "${DIR_PATH}"/"${FILE_LS}"
  else
    ./ft_ls ${flags[$i]} "ex" "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "/Users/gkarina/Desktop" "${PTF}file6" "${PTF}file5" "main.c" "../ft_ping" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls ${flags[$i]} "ex" "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "/Users/gkarina/Desktop" "${PTF}file6" "${PTF}file5" "main.c" "../ft_ping" > "${DIR_PATH}"/"${FILE_LS}"
  fi

  DIFF=$(diff ${DIR_PATH}/${FILE_FT_LS} ${DIR_PATH}/${FILE_LS})
  echo ${DIFF} > ${DIR_PATH}/${DIFF_FILE}
  if [ -z "$DIFF" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_FILE}"
  fi
done
