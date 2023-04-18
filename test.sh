#!/bin/zsh

TEST_DIRECTORY_PATH="/Users/gkarina/tests/"
PTF="/Users/gkarina/Desktop/" #path to file

make

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
    ./ft_ls "/Users/gkarina/Desktop" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls "/Users/gkarina/Desktop" > "${DIR_PATH}"/"${FILE_LS}"
  else
    ./ft_ls ${flags[$i]} "/Users/gkarina/Desktop" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls ${flags[$i]} "/Users/gkarina/Desktop" > "${DIR_PATH}"/"${FILE_LS}"
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

echo "${GREEN}TEST ONLY FILES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ./ft_ls "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" > "${DIR_PATH}"/"${FILE_LS}"
  else
    ./ft_ls ${flags[$i]} "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" > "${DIR_PATH}"/"${FILE_FT_LS}"
    ls ${flags[$i]} "${PTF}file3" "${PTF}file2" "${PTF}file4" "${PTF}file1" "${PTF}file7" "${PTF}file6" "${PTF}file5" > "${DIR_PATH}"/"${FILE_LS}"
  fi

  DIFF=$(diff ${DIR_PATH}/${FILE_FT_LS} ${DIR_PATH}/${FILE_LS})
  echo ${DIFF} > ${DIR_PATH}/${DIFF_FILE}
  if [ -z "$DIFF" ]; then
    echo "OK" ${DIR_PATH}
  else
    echo "Incorrect output. Find information in ${DIR_PATH}/${DIFF_FILE}"
  fi
done
