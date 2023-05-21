#!/bin/zsh

TEST_DIRECTORY_PATH=${HOME}"/tests/regular/"
TEST_DIRECTORY_PATH_BONUS=${HOME}"/tests/bonus/"
TEST_DIRECTORY_PATH_COLOR_BONUS=${HOME}"/tests/color_bonus/"
PTF=${HOME}"/Desktop/" #path to file

F1="${PTF}file1"
F2="${PTF}file2"
F3="${PTF}file3"
F4="${PTF}file4"
F5="${PTF}file5"
F6="${PTF}file6"
F7="${PTF}file7"
NF="../new_file"
EX="ex"
FIRST_DIR="${HOME}/Desktop"
SECOND_DIR="ex"
THIRD_DIR="${HOME}/Desktop/codam"
FOURTH_DIR="${HOME}/Desktop/boykonet/ft_ls"
FIFTH_DIR="${HOME}/Desktop/boykonet"

#touch ${F1} ${F2}
#touch ${F3}
#touch ${F4}
#touch ${F5} ${F6} ${F7}
#touch ${NF}
mkdir -p ${EX}
mkdir -p ${EX}/dir1 ${EX}/dir1/dir3 ${EX}/dir4 ${EX}/file1 ${EX}/file2 ${EX}/file3 ${EX}/dir2 ${EX}/file
ln -s ${EX}/file ${EX}/link
mknod myfifo ${EX}/myfifo

make

dirs=("regular" "R"   "r"  "a"  "l"  "t"  "Rr"  "Ra"  "Rl"  "Rt"  "ra"  "rl"  "rt"  "al"  "at"  "lt"  "Rra"  "Rrl"  "Rrt"  "Ral"  "Rat"  "Rlt"  "ral"  "rat"  "rlt"  "alt"  "Rral"  "Rrat"  "Rrlt"  "Ralt"  "ralt"  "Rralt")
flags=(""      "-R"  "-r" "-a" "-l" "-t" "-Rr" "-Ra" "-Rl" "-Rt" "-ra" "-rl" "-rt" "-al" "-at" "-lt" "-Rra" "-Rrl" "-Rrt" "-Ral" "-Rat" "-Rlt" "-ral" "-rat" "-rlt" "-alt" "-Rral" "-Rrat" "-Rrlt" "-Ralt" "-ralt" "-Rralt")

dirs_bonus=(  "d"  "f"  "g"  "Rd"  "Rf"  "Rg"  "rd"  "rf"  "rg"  "ad"  "af"  "ag"  "ld"  "lf"  "lg"  "td"  "tf"  "tg"  "df"  "dg"  "fg"  "Rrd"  "Rrf"  "Rrg"  "Rad"  "Raf"  "Rag"  "Rld"  "Rlf"  "Rlg"  "Rtd"  "Rtf"  "Rtg"  "Rdf"  "Rdg"  "Rfg"  "rad"  "raf"  "rag"  "rld"  "rlf"  "rlg"  "rtd"  "rtf"  "rtg"  "rdf"  "rdg"  "rfg"  "ald"  "alf"  "alg"  "atd"  "atf"  "atg"  "adf"  "adg"  "afg"  "ltd"  "ltf"  "ltg"  "ldf"  "ldg"  "lfg"  "tdf"  "tdg"  "tfg"  "dfg"  "Rrad"  "Rraf"  "Rrag"  "Rrld"  "Rrlf"  "Rrlg"  "Rrtd"  "Rrtf"  "Rrtg"  "Rrdf"  "Rrdg"  "Rrfg"  "Rald"  "Ralf"  "Ralg"  "Ratd"  "Ratf"  "Ratg"  "Radf"  "Radg"  "Rafg"  "Rltd"  "Rltf"  "Rltg"  "Rldf"  "Rldg"  "Rlfg"  "Rtdf"  "Rtdg"  "Rtfg"  "Rdfg"  "rald"  "ralf"  "ralg"  "ratd"  "ratf"  "ratg"  "radf"  "radg"  "rafg"  "rltd"  "rltf"  "rltg"  "rldf"  "rldg"  "rlfg"  "rtdf"  "rtdg"  "rtfg"  "rdfg"  "altd"  "altf"  "altg"  "aldf"  "aldg"  "alfg"  "atdf"  "atdg"  "atfg"  "adfg"  "ltdf"  "ltdg"  "ltfg"  "ldfg"  "tdfg"  "Rrald"  "Rralf"  "Rralg"  "Rratd"  "Rratf"  "Rratg"  "Rradf"  "Rradg"  "Rrafg"  "Rrltd"  "Rrltf"  "Rrltg"  "Rrldf"  "Rrldg"  "Rrlfg"  "Rrtdf"  "Rrtdg"  "Rrtfg"  "Rrdfg"  "Raltd"  "Raltf"  "Raltg"  "Raldf"  "Raldg"  "Ralfg"  "Ratdf"  "Ratdg"  "Ratfg"  "Radfg"  "Rltdf"  "Rltdg"  "Rltfg"  "Rldfg"  "Rtdfg"  "raltd"  "raltf"  "raltg"  "raldf"  "raldg"  "ralfg"  "ratdf"  "ratdg"  "ratfg"  "radfg"  "rltdf"  "rltdg"  "rltfg"  "rldfg"  "rtdfg"  "altdf"  "altdg"  "altfg"  "aldfg"  "atdfg"  "ltdfg"  "Rraltd"  "Rraltf"  "Rraltg"  "Rraldf"  "Rraldg"  "Rralfg"  "Rratdf"  "Rratdg"  "Rratfg"  "Rradfg"  "Rrltdf"  "Rrltdg"  "Rrltfg"  "Rrldfg"  "Rrtdfg"  "Raltdf"  "Raltdg"  "Raltfg"  "Raldfg"  "Ratdfg"  "Rltdfg"  "raltdf"  "raltdg"  "raltfg"  "raldfg"  "ratdfg"  "rltdfg"  "altdfg"  "Rraltdf"  "Rraltdg"  "Rraltfg"  "Rraldfg"  "Rratdfg"  "Rrltdfg"  "Raltdfg"  "raltdfg"  "Rraltdfg")
flags_bonus=("-d" "-f" "-g" "-Rd" "-Rf" "-Rg" "-rd" "-rf" "-rg" "-ad" "-af" "-ag" "-ld" "-lf" "-lg" "-td" "-tf" "-tg" "-df" "-dg" "-fg" "-Rrd" "-Rrf" "-Rrg" "-Rad" "-Raf" "-Rag" "-Rld" "-Rlf" "-Rlg" "-Rtd" "-Rtf" "-Rtg" "-Rdf" "-Rdg" "-Rfg" "-rad" "-raf" "-rag" "-rld" "-rlf" "-rlg" "-rtd" "-rtf" "-rtg" "-rdf" "-rdg" "-rfg" "-ald" "-alf" "-alg" "-atd" "-atf" "-atg" "-adf" "-adg" "-afg" "-ltd" "-ltf" "-ltg" "-ldf" "-ldg" "-lfg" "-tdf" "-tdg" "-tfg" "-dfg" "-Rrad" "-Rraf" "-Rrag" "-Rrld" "-Rrlf" "-Rrlg" "-Rrtd" "-Rrtf" "-Rrtg" "-Rrdf" "-Rrdg" "-Rrfg" "-Rald" "-Ralf" "-Ralg" "-Ratd" "-Ratf" "-Ratg" "-Radf" "-Radg" "-Rafg" "-Rltd" "-Rltf" "-Rltg" "-Rldf" "-Rldg" "-Rlfg" "-Rtdf" "-Rtdg" "-Rtfg" "-Rdfg" "-rald" "-ralf" "-ralg" "-ratd" "-ratf" "-ratg" "-radf" "-radg" "-rafg" "-rltd" "-rltf" "-rltg" "-rldf" "-rldg" "-rlfg" "-rtdf" "-rtdg" "-rtfg" "-rdfg" "-altd" "-altf" "-altg" "-aldf" "-aldg" "-alfg" "-atdf" "-atdg" "-atfg" "-adfg" "-ltdf" "-ltdg" "-ltfg" "-ldfg" "-tdfg" "-Rrald" "-Rralf" "-Rralg" "-Rratd" "-Rratf" "-Rratg" "-Rradf" "-Rradg" "-Rrafg" "-Rrltd" "-Rrltf" "-Rrltg" "-Rrldf" "-Rrldg" "-Rrlfg" "-Rrtdf" "-Rrtdg" "-Rrtfg" "-Rrdfg" "-Raltd" "-Raltf" "-Raltg" "-Raldf" "-Raldg" "-Ralfg" "-Ratdf" "-Ratdg" "-Ratfg" "-Radfg" "-Rltdf" "-Rltdg" "-Rltfg" "-Rldfg" "-Rtdfg" "-raltd" "-raltf" "-raltg" "-raldf" "-raldg" "-ralfg" "-ratdf" "-ratdg" "-ratfg" "-radfg" "-rltdf" "-rltdg" "-rltfg" "-rldfg" "-rtdfg" "-altdf" "-altdg" "-altfg" "-aldfg" "-atdfg" "-ltdfg" "-Rraltd" "-Rraltf" "-Rraltg" "-Rraldf" "-Rraldg" "-Rralfg" "-Rratdf" "-Rratdg" "-Rratfg" "-Rradfg" "-Rrltdf" "-Rrltdg" "-Rrltfg" "-Rrldfg" "-Rrtdfg" "-Raltdf" "-Raltdg" "-Raltfg" "-Raldfg" "-Ratdfg" "-Rltdfg" "-raltdf" "-raltdg" "-raltfg" "-raldfg" "-ratdfg" "-rltdfg" "-altdfg" "-Rraltdf" "-Rraltdg" "-Rraltfg" "-Rraldfg" "-Rratdfg" "-Rrltdfg" "-Raltdfg" "-raltdfg" "-Rraltdfg")


GREEN='\033[0;32m'
NC='\033[0m' # No Color


#--------------------------------------------------------------------------
FT_LS_OUT="ft_ls_out"
FT_LS_ERR="ft_ls_err"
LS_OUT="ls_out"
LS_ERR="ls_err"
DIFF_OUT="diff_out"
DIFF_ERR="diff_err"


WITHOUT_ARGUMENTS_SUFFIX="-without-arguments"
DOT_SUFFIX="-dot"
DIR_SUFFIX="-dir"
FILE_SUFFIX="-file"
FILES_AND_DIRS_SUFFIX="-dir-file"
FILE_NOT_FOUND_SUFFIX="-file_not_found"
INCORRECT_FLAG_SUFFIX="-incorrect-flag"

echo "${GREEN}WITHOUT ARGUMENTS${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}${WITHOUT_ARGUMENTS_SUFFIX}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
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

echo "\n${GREEN}DOT${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}${DOT_SUFFIX}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls . > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls . > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} . > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} . > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
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

echo "\n${GREEN}TEST ONLY DIRECTORIES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}${DIR_SUFFIX}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${FIRST_DIR} ${SECOND_DIR} ${THIRD_DIR} ${FOURTH_DIR} ${FIFTH_DIR} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${FIRST_DIR} ${SECOND_DIR} ${THIRD_DIR} ${FOURTH_DIR} ${FIFTH_DIR} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} ${FIRST_DIR} ${SECOND_DIR} ${THIRD_DIR} ${FOURTH_DIR} ${FIFTH_DIR} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} ${FIRST_DIR} ${SECOND_DIR} ${THIRD_DIR} ${FOURTH_DIR} ${FIFTH_DIR} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
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

echo "\n${GREEN}TEST ONLY FILES${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}${FILE_SUFFIX}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
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

echo "\n${GREEN}TEST FILES AND DIRS${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}${FILES_AND_DIRS_SUFFIX}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${SECOND_DIR} ${F3} ${F2} ${FIFTH_DIR} ${F4} ${FOURTH_DIR} ${F1} ${F7} ${FIRST_DIR} ${F6} ${F5} "main.c" ${THIRD_DIR} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${SECOND_DIR} ${F3} ${F2} ${FIFTH_DIR} ${F4} ${FOURTH_DIR} ${F1} ${F7} ${FIRST_DIR} ${F6} ${F5} "main.c" ${THIRD_DIR} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} ${SECOND_DIR} ${F3} ${F2} ${FIFTH_DIR} ${F4} ${FOURTH_DIR} ${F1} ${F7} ${FIRST_DIR} ${F6} ${F5} "main.c" ${THIRD_DIR} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} ${SECOND_DIR} ${F3} ${F2} ${FIFTH_DIR} ${F4} ${FOURTH_DIR} ${F1} ${F7} ${FIRST_DIR} ${F6} ${F5} "main.c" ${THIRD_DIR} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
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

FILE_NOT_FOUND="file_not_found"

echo "\n${GREEN}TEST FILE NOT FOUND${NC}\n"

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}${FILE_NOT_FOUND_SUFFIX}
  mkdir -p ${DIR_PATH}
  if [ -z "${flags[$i]}" ]; then
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${FILE_NOT_FOUND} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${FILE_NOT_FOUND} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} ${FILE_NOT_FOUND} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
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

echo "\n${GREEN}TEST INCORRECT FLAG${NC}\n"

INCORRECT_FLAG="incorrect_flag"

i=0
DIR_PATH=${TEST_DIRECTORY_PATH}${INCORRECT_FLAG}${INCORRECT_FLAG_SUFFIX}
mkdir -p ${DIR_PATH}
ASAN_OPTIONS=detect_leaks=1 ./ft_ls -, "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
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



printf "\n\n-----------------------------------------------------------------------------\n\n"


echo "${GREEN}BONUS PART${NC}\n\n"

echo "${GREEN}WITHOUT ARGUMENTS${NC}\n"

i=0
sz=${#dirs_bonus[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${dirs_bonus[$i]}${WITHOUT_ARGUMENTS_SUFFIX}
  mkdir -p ${DIR_PATH}
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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

echo "\n${GREEN}DOT${NC}\n"

i=0
sz=${#dirs_bonus[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${dirs_bonus[$i]}${DOT_SUFFIX}
  mkdir -p ${DIR_PATH}
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} . > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} . > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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

echo "\n${GREEN}TEST ONLY DIRECTORIES${NC}\n"

i=0
sz=${#dirs_bonus[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${dirs_bonus[$i]}${DIR_SUFFIX}
  mkdir -p ${DIR_PATH}
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} ${FIRST_DIR} ${SECOND_DIR} ${THIRD_DIR} ${FOURTH_DIR} ${FIFTH_DIR} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} ${FIRST_DIR} ${SECOND_DIR} ${THIRD_DIR} ${FOURTH_DIR} ${FIFTH_DIR} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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

echo "\n${GREEN}TEST ONLY FILES${NC}\n"

i=0
sz=${#dirs_bonus[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${dirs_bonus[$i]}${FILE_SUFFIX}
  mkdir -p ${DIR_PATH}
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} ${F3} ${F2} ${F4} ${F1} ${F7} ${F6} ${F5} "main.c" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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

echo "\n${GREEN}TEST FILES AND DIRS${NC}\n"

i=0
sz=${#dirs_bonus[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${dirs_bonus[$i]}${FILES_AND_DIRS_SUFFIX}
  mkdir -p ${DIR_PATH}
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} ${SECOND_DIR} ${F3} ${F2} ${FIFTH_DIR} ${F4} ${FOURTH_DIR} ${F1} ${F7} ${FIRST_DIR} ${F6} ${F5} "main.c" ${THIRD_DIR} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} ${SECOND_DIR} ${F3} ${F2} ${FIFTH_DIR} ${F4} ${FOURTH_DIR} ${F1} ${F7} ${FIRST_DIR} ${F6} ${F5} "main.c" ${THIRD_DIR} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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


FILE_NOT_FOUND="file_not_found"


echo "\n${GREEN}TEST FILE NOT FOUND${NC}\n"

i=0
sz=${#dirs_bonus[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${dirs_bonus[$i]}${FILE_NOT_FOUND_SUFFIX}
  mkdir -p ${DIR_PATH}
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} ${FILE_NOT_FOUND} > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} ${FILE_NOT_FOUND} > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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
