#!/bin/zsh

TEST_DIRECTORY_PATH="../../tests/"

make -C ../

dirs=("regular" "recursive" "reverse" "long_format" "dot_dirs" "time_last_modified")
flags=(""       "-R"        "-r"      "-l"          "-a"       "-t")

i=0
sz=${#dirs[@]}
for i in `seq $sz`; do
  DIR_PATH=${TEST_DIRECTORY_PATH}${dirs[$i]}
  mkdir -p $DIR_PATH
  if [ -z "$flags[$i]" ]; then
    ../ft_ls ../ > "$DIR_PATH"/ft_ls_out
    ls ../ > "$DIR_PATH"/ls_out
  else
    ../ft_ls $flags[$i] ../ > "$DIR_PATH"/ft_ls_out
    ls $flags[$i] ../ > "$DIR_PATH"/ls_out
  fi

  DIFF=$(diff $DIR_PATH/ft_ls_out $DIR_PATH/ls_out)
  echo $DIFF > $DIR_PATH/diff_output
  if [ -z "$DIFF" ]; then
    echo "OK" $DIR_PATH
  else
    echo "Incorrect output. Find information in $DIR_PATH/diff_output"
  fi
done
