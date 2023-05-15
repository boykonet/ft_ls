#!/bin/zsh

TEST_DIRECTORY_PATH=${HOME}"/tests/regular/"
TEST_DIRECTORY_PATH_BONUS=${HOME}"/tests/bonus/"
PTF=${HOME}"/Desktop/" #path to file

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
flags=(""      "-R"  "-r" "-a" "-l" "-t" "-Rr" "-Ra" "-Rl" "-Rt" "-ra" "-rl" "-rt" "-al" "-at" "-lt" "-Rra" "-Rrl" "-Rrt" "-Ral" "-Rat" "-Rlt" "-ral" "-rat" "-rlt" "-alt" "-Rral" "-Rrat" "-Rrlt" "-Ralt" "-ralt" "-Rralt")

dirs_bonus=(  "R"  "r"  "a"  "l"  "t"  "d"  "f"  "g"  "u"  "Rr"  "Ra"  "Rl"  "Rt"  "Rd"  "Rf"  "Rg"  "Ru"  "ra"  "rl"  "rt"  "rd"  "rf"  "rg"  "ru"  "al"  "at"  "ad"  "af"  "ag"  "au"  "lt"  "ld"  "lf"  "lg"  "lu"  "td"  "tf"  "tg"  "tu"  "df"  "dg"  "du"  "fg"  "fu"  "gu"  "Rra"  "Rrl"  "Rrt"  "Rrd"  "Rrf"  "Rrg"  "Rru"  "Ral"  "Rat"  "Rad"  "Raf"  "Rag"  "Rau"  "Rlt"  "Rld"  "Rlf"  "Rlg"  "Rlu"  "Rtd"  "Rtf"  "Rtg"  "Rtu"  "Rdf"  "Rdg"  "Rdu"  "Rfg"  "Rfu"  "Rgu"  "ral"  "rat"  "rad"  "raf"  "rag"  "rau"  "rlt"  "rld"  "rlf"  "rlg"  "rlu"  "rtd"  "rtf"  "rtg"  "rtu"  "rdf"  "rdg"  "rdu"  "rfg"  "rfu"  "rgu"  "alt"  "ald"  "alf"  "alg"  "alu"  "atd"  "atf"  "atg"  "atu"  "adf"  "adg"  "adu"  "afg"  "afu"  "agu"  "ltd"  "ltf"  "ltg"  "ltu"  "ldf"  "ldg"  "ldu"  "lfg"  "lfu"  "lgu"  "tdf"  "tdg"  "tdu"  "tfg"  "tfu"  "tgu"  "dfg"  "dfu"  "dgu"  "fgu"  "Rral"  "Rrat"  "Rrad"  "Rraf"  "Rrag"  "Rrau"  "Rrlt"  "Rrld"  "Rrlf"  "Rrlg"  "Rrlu"  "Rrtd"  "Rrtf"  "Rrtg"  "Rrtu"  "Rrdf"  "Rrdg"  "Rrdu"  "Rrfg"  "Rrfu"  "Rrgu"  "Ralt"  "Rald"  "Ralf"  "Ralg"  "Ralu"  "Ratd"  "Ratf"  "Ratg"  "Ratu"  "Radf"  "Radg"  "Radu"  "Rafg"  "Rafu"  "Ragu"  "Rltd"  "Rltf"  "Rltg"  "Rltu"  "Rldf"  "Rldg"  "Rldu"  "Rlfg"  "Rlfu"  "Rlgu"  "Rtdf"  "Rtdg"  "Rtdu"  "Rtfg"  "Rtfu"  "Rtgu"  "Rdfg"  "Rdfu"  "Rdgu"  "Rfgu"  "ralt"  "rald"  "ralf"  "ralg"  "ralu"  "ratd"  "ratf"  "ratg"  "ratu"  "radf"  "radg"  "radu"  "rafg"  "rafu"  "ragu"  "rltd"  "rltf"  "rltg"  "rltu"  "rldf"  "rldg"  "rldu"  "rlfg"  "rlfu"  "rlgu"  "rtdf"  "rtdg"  "rtdu"  "rtfg"  "rtfu"  "rtgu"  "rdfg"  "rdfu"  "rdgu"  "rfgu"  "altd"  "altf"  "altg"  "altu"  "aldf"  "aldg"  "aldu"  "alfg"  "alfu"  "algu"  "atdf"  "atdg"  "atdu"  "atfg"  "atfu"  "atgu"  "adfg"  "adfu"  "adgu"  "afgu"  "ltdf"  "ltdg"  "ltdu"  "ltfg"  "ltfu"  "ltgu"  "ldfg"  "ldfu"  "ldgu"  "lfgu"  "tdfg"  "tdfu"  "tdgu"  "tfgu"  "dfgu"  "Rralt"  "Rrald"  "Rralf"  "Rralg"  "Rralu"  "Rratd"  "Rratf"  "Rratg"  "Rratu"  "Rradf"  "Rradg"  "Rradu"  "Rrafg"  "Rrafu"  "Rragu"  "Rrltd"  "Rrltf"  "Rrltg"  "Rrltu"  "Rrldf"  "Rrldg"  "Rrldu"  "Rrlfg"  "Rrlfu"  "Rrlgu"  "Rrtdf"  "Rrtdg"  "Rrtdu"  "Rrtfg"  "Rrtfu"  "Rrtgu"  "Rrdfg"  "Rrdfu"  "Rrdgu"  "Rrfgu"  "Raltd"  "Raltf"  "Raltg"  "Raltu"  "Raldf"  "Raldg"  "Raldu"  "Ralfg"  "Ralfu"  "Ralgu"  "Ratdf"  "Ratdg"  "Ratdu"  "Ratfg"  "Ratfu"  "Ratgu"  "Radfg"  "Radfu"  "Radgu"  "Rafgu"  "Rltdf"  "Rltdg"  "Rltdu"  "Rltfg"  "Rltfu"  "Rltgu"  "Rldfg"  "Rldfu"  "Rldgu"  "Rlfgu"  "Rtdfg"  "Rtdfu"  "Rtdgu"  "Rtfgu"  "Rdfgu"  "raltd"  "raltf"  "raltg"  "raltu"  "raldf"  "raldg"  "raldu"  "ralfg"  "ralfu"  "ralgu"  "ratdf"  "ratdg"  "ratdu"  "ratfg"  "ratfu"  "ratgu"  "radfg"  "radfu"  "radgu"  "rafgu"  "rltdf"  "rltdg"  "rltdu"  "rltfg"  "rltfu"  "rltgu"  "rldfg"  "rldfu"  "rldgu"  "rlfgu"  "rtdfg"  "rtdfu"  "rtdgu"  "rtfgu"  "rdfgu"  "altdf"  "altdg"  "altdu"  "altfg"  "altfu"  "altgu"  "aldfg"  "aldfu"  "aldgu"  "alfgu"  "atdfg"  "atdfu"  "atdgu"  "atfgu"  "adfgu"  "ltdfg"  "ltdfu"  "ltdgu"  "ltfgu"  "ldfgu"  "tdfgu"  "Rraltd"  "Rraltf"  "Rraltg"  "Rraltu"  "Rraldf"  "Rraldg"  "Rraldu"  "Rralfg"  "Rralfu"  "Rralgu"  "Rratdf"  "Rratdg"  "Rratdu"  "Rratfg"  "Rratfu"  "Rratgu"  "Rradfg"  "Rradfu"  "Rradgu"  "Rrafgu"  "Rrltdf"  "Rrltdg"  "Rrltdu"  "Rrltfg"  "Rrltfu"  "Rrltgu"  "Rrldfg"  "Rrldfu"  "Rrldgu"  "Rrlfgu"  "Rrtdfg"  "Rrtdfu"  "Rrtdgu"  "Rrtfgu"  "Rrdfgu"  "Raltdf"  "Raltdg"  "Raltdu"  "Raltfg"  "Raltfu"  "Raltgu"  "Raldfg"  "Raldfu"  "Raldgu"  "Ralfgu"  "Ratdfg"  "Ratdfu"  "Ratdgu"  "Ratfgu"  "Radfgu"  "Rltdfg"  "Rltdfu"  "Rltdgu"  "Rltfgu"  "Rldfgu"  "Rtdfgu"  "raltdf"  "raltdg"  "raltdu"  "raltfg"  "raltfu"  "raltgu"  "raldfg"  "raldfu"  "raldgu"  "ralfgu"  "ratdfg"  "ratdfu"  "ratdgu"  "ratfgu"  "radfgu"  "rltdfg"  "rltdfu"  "rltdgu"  "rltfgu"  "rldfgu"  "rtdfgu"  "altdfg"  "altdfu"  "altdgu"  "altfgu"  "aldfgu"  "atdfgu"  "ltdfgu"  "Rraltdf"  "Rraltdg"  "Rraltdu"  "Rraltfg"  "Rraltfu"  "Rraltgu"  "Rraldfg"  "Rraldfu"  "Rraldgu"  "Rralfgu"  "Rratdfg"  "Rratdfu"  "Rratdgu"  "Rratfgu"  "Rradfgu"  "Rrltdfg"  "Rrltdfu"  "Rrltdgu"  "Rrltfgu"  "Rrldfgu"  "Rrtdfgu"  "Raltdfg"  "Raltdfu"  "Raltdgu"  "Raltfgu"  "Raldfgu"  "Ratdfgu"  "Rltdfgu"  "raltdfg"  "raltdfu"  "raltdgu"  "raltfgu"  "raldfgu"  "ratdfgu"  "rltdfgu"  "altdfgu"  "Rraltdfg"  "Rraltdfu"  "Rraltdgu"  "Rraltfgu"  "Rraldfgu"  "Rratdfgu"  "Rrltdfgu"  "Raltdfgu"  "raltdfgu"  "Rraltdfgu")
flags_bonus=("-R" "-r" "-a" "-l" "-t" "-d" "-f" "-g" "-u" "-Rr" "-Ra" "-Rl" "-Rt" "-Rd" "-Rf" "-Rg" "-Ru" "-ra" "-rl" "-rt" "-rd" "-rf" "-rg" "-ru" "-al" "-at" "-ad" "-af" "-ag" "-au" "-lt" "-ld" "-lf" "-lg" "-lu" "-td" "-tf" "-tg" "-tu" "-df" "-dg" "-du" "-fg" "-fu" "-gu" "-Rra" "-Rrl" "-Rrt" "-Rrd" "-Rrf" "-Rrg" "-Rru" "-Ral" "-Rat" "-Rad" "-Raf" "-Rag" "-Rau" "-Rlt" "-Rld" "-Rlf" "-Rlg" "-Rlu" "-Rtd" "-Rtf" "-Rtg" "-Rtu" "-Rdf" "-Rdg" "-Rdu" "-Rfg" "-Rfu" "-Rgu" "-ral" "-rat" "-rad" "-raf" "-rag" "-rau" "-rlt" "-rld" "-rlf" "-rlg" "-rlu" "-rtd" "-rtf" "-rtg" "-rtu" "-rdf" "-rdg" "-rdu" "-rfg" "-rfu" "-rgu" "-alt" "-ald" "-alf" "-alg" "-alu" "-atd" "-atf" "-atg" "-atu" "-adf" "-adg" "-adu" "-afg" "-afu" "-agu" "-ltd" "-ltf" "-ltg" "-ltu" "-ldf" "-ldg" "-ldu" "-lfg" "-lfu" "-lgu" "-tdf" "-tdg" "-tdu" "-tfg" "-tfu" "-tgu" "-dfg" "-dfu" "-dgu" "-fgu" "-Rral" "-Rrat" "-Rrad" "-Rraf" "-Rrag" "-Rrau" "-Rrlt" "-Rrld" "-Rrlf" "-Rrlg" "-Rrlu" "-Rrtd" "-Rrtf" "-Rrtg" "-Rrtu" "-Rrdf" "-Rrdg" "-Rrdu" "-Rrfg" "-Rrfu" "-Rrgu" "-Ralt" "-Rald" "-Ralf" "-Ralg" "-Ralu" "-Ratd" "-Ratf" "-Ratg" "-Ratu" "-Radf" "-Radg" "-Radu" "-Rafg" "-Rafu" "-Ragu" "-Rltd" "-Rltf" "-Rltg" "-Rltu" "-Rldf" "-Rldg" "-Rldu" "-Rlfg" "-Rlfu" "-Rlgu" "-Rtdf" "-Rtdg" "-Rtdu" "-Rtfg" "-Rtfu" "-Rtgu" "-Rdfg" "-Rdfu" "-Rdgu" "-Rfgu" "-ralt" "-rald" "-ralf" "-ralg" "-ralu" "-ratd" "-ratf" "-ratg" "-ratu" "-radf" "-radg" "-radu" "-rafg" "-rafu" "-ragu" "-rltd" "-rltf" "-rltg" "-rltu" "-rldf" "-rldg" "-rldu" "-rlfg" "-rlfu" "-rlgu" "-rtdf" "-rtdg" "-rtdu" "-rtfg" "-rtfu" "-rtgu" "-rdfg" "-rdfu" "-rdgu" "-rfgu" "-altd" "-altf" "-altg" "-altu" "-aldf" "-aldg" "-aldu" "-alfg" "-alfu" "-algu" "-atdf" "-atdg" "-atdu" "-atfg" "-atfu" "-atgu" "-adfg" "-adfu" "-adgu" "-afgu" "-ltdf" "-ltdg" "-ltdu" "-ltfg" "-ltfu" "-ltgu" "-ldfg" "-ldfu" "-ldgu" "-lfgu" "-tdfg" "-tdfu" "-tdgu" "-tfgu" "-dfgu" "-Rralt" "-Rrald" "-Rralf" "-Rralg" "-Rralu" "-Rratd" "-Rratf" "-Rratg" "-Rratu" "-Rradf" "-Rradg" "-Rradu" "-Rrafg" "-Rrafu" "-Rragu" "-Rrltd" "-Rrltf" "-Rrltg" "-Rrltu" "-Rrldf" "-Rrldg" "-Rrldu" "-Rrlfg" "-Rrlfu" "-Rrlgu" "-Rrtdf" "-Rrtdg" "-Rrtdu" "-Rrtfg" "-Rrtfu" "-Rrtgu" "-Rrdfg" "-Rrdfu" "-Rrdgu" "-Rrfgu" "-Raltd" "-Raltf" "-Raltg" "-Raltu" "-Raldf" "-Raldg" "-Raldu" "-Ralfg" "-Ralfu" "-Ralgu" "-Ratdf" "-Ratdg" "-Ratdu" "-Ratfg" "-Ratfu" "-Ratgu" "-Radfg" "-Radfu" "-Radgu" "-Rafgu" "-Rltdf" "-Rltdg" "-Rltdu" "-Rltfg" "-Rltfu" "-Rltgu" "-Rldfg" "-Rldfu" "-Rldgu" "-Rlfgu" "-Rtdfg" "-Rtdfu" "-Rtdgu" "-Rtfgu" "-Rdfgu" "-raltd" "-raltf" "-raltg" "-raltu" "-raldf" "-raldg" "-raldu" "-ralfg" "-ralfu" "-ralgu" "-ratdf" "-ratdg" "-ratdu" "-ratfg" "-ratfu" "-ratgu" "-radfg" "-radfu" "-radgu" "-rafgu" "-rltdf" "-rltdg" "-rltdu" "-rltfg" "-rltfu" "-rltgu" "-rldfg" "-rldfu" "-rldgu" "-rlfgu" "-rtdfg" "-rtdfu" "-rtdgu" "-rtfgu" "-rdfgu" "-altdf" "-altdg" "-altdu" "-altfg" "-altfu" "-altgu" "-aldfg" "-aldfu" "-aldgu" "-alfgu" "-atdfg" "-atdfu" "-atdgu" "-atfgu" "-adfgu" "-ltdfg" "-ltdfu" "-ltdgu" "-ltfgu" "-ldfgu" "-tdfgu" "-Rraltd" "-Rraltf" "-Rraltg" "-Rraltu" "-Rraldf" "-Rraldg" "-Rraldu" "-Rralfg" "-Rralfu" "-Rralgu" "-Rratdf" "-Rratdg" "-Rratdu" "-Rratfg" "-Rratfu" "-Rratgu" "-Rradfg" "-Rradfu" "-Rradgu" "-Rrafgu" "-Rrltdf" "-Rrltdg" "-Rrltdu" "-Rrltfg" "-Rrltfu" "-Rrltgu" "-Rrldfg" "-Rrldfu" "-Rrldgu" "-Rrlfgu" "-Rrtdfg" "-Rrtdfu" "-Rrtdgu" "-Rrtfgu" "-Rrdfgu" "-Raltdf" "-Raltdg" "-Raltdu" "-Raltfg" "-Raltfu" "-Raltgu" "-Raldfg" "-Raldfu" "-Raldgu" "-Ralfgu" "-Ratdfg" "-Ratdfu" "-Ratdgu" "-Ratfgu" "-Radfgu" "-Rltdfg" "-Rltdfu" "-Rltdgu" "-Rltfgu" "-Rldfgu" "-Rtdfgu" "-raltdf" "-raltdg" "-raltdu" "-raltfg" "-raltfu" "-raltgu" "-raldfg" "-raldfu" "-raldgu" "-ralfgu" "-ratdfg" "-ratdfu" "-ratdgu" "-ratfgu" "-radfgu" "-rltdfg" "-rltdfu" "-rltdgu" "-rltfgu" "-rldfgu" "-rtdfgu" "-altdfg" "-altdfu" "-altdgu" "-altfgu" "-aldfgu" "-atdfgu" "-ltdfgu" "-Rraltdf" "-Rraltdg" "-Rraltdu" "-Rraltfg" "-Rraltfu" "-Rraltgu" "-Rraldfg" "-Rraldfu" "-Rraldgu" "-Rralfgu" "-Rratdfg" "-Rratdfu" "-Rratdgu" "-Rratfgu" "-Rradfgu" "-Rrltdfg" "-Rrltdfu" "-Rrltdgu" "-Rrltfgu" "-Rrldfgu" "-Rrtdfgu" "-Raltdfg" "-Raltdfu" "-Raltdgu" "-Raltfgu" "-Raldfgu" "-Ratdfgu" "-Rltdfgu" "-raltdfg" "-raltdfu" "-raltdgu" "-raltfgu" "-raldfgu" "-ratdfgu" "-rltdfgu" "-altdfgu" "-Rraltdfg" "-Rraltdfu" "-Rraltdgu" "-Rraltfgu" "-Rraldfgu" "-Rratdfgu" "-Rrltdfgu" "-Raltdfgu" "-raltdfgu" "-Rraltdfgu")

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
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${HOME}"/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${HOME}"/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} ${HOME}"/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} ${HOME}"/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
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
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls "ex" ${F3} ${F2} ${F4} ${F1} ${F7} ${HOME}"/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls "ex" ${F3} ${F2} ${F4} ${F1} ${F7} ${HOME}"/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
  else
    ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags[$i]} "ex" ${F3} ${F2} ${F4} ${F1} ${F7} ${HOME}"/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
    ls ${flags[$i]} "ex" ${F3} ${F2} ${F4} ${F1} ${F7} ${HOME}"/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}
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
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} ${HOME}"/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} ${HOME}"/Desktop" "ex" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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
  ASAN_OPTIONS=detect_leaks=1 ./ft_ls ${flags_bonus[$i]} "ex" ${F3} ${F2} ${F4} ${F1} ${F7} ${HOME}"/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${FT_LS_OUT} 2>${DIR_PATH}/${FT_LS_ERR}
  ls ${flags_bonus[$i]} "ex" ${F3} ${F2} ${F4} ${F1} ${F7} ${HOME}"/Desktop" ${F6} ${F5} "main.c" "../ft_ping" > ${DIR_PATH}/${LS_OUT} 2>${DIR_PATH}/${LS_ERR}

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

#--------------------------------------------------------------------------


echo "\n${GREEN}TEST INCORRECT FLAG${NC}\n"

INCORRECT_FLAG="incorrect_flag"

i=0
DIR_PATH=${TEST_DIRECTORY_PATH_BONUS}${INCORRECT_FLAG}${INCORRECT_FLAG_SUFFIX}
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
