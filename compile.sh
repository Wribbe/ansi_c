#!/bin/sh

executable_dir="executables"
flags="-std=c99 -pedantic -Werror -Wall -ggdb"

if [ ! -d "$executable_dir" ]; then
  mkdir "$executable_dir"
fi

for file in ./tests/*; do
  case "$file" in
    *".c"*)
      exec_name=$(echo $file | cut -c 9- | rev | cut -c 3- | rev)
      cc "$file" -o "${executable_dir}/${exec_name}" $flags
      ;;
  esac
done
for file in ./*; do
  case "$file" in
    *".c"*)
      exec_name=$(echo $file | cut -c 3- | rev | cut -c 3- | rev)
      cc "$file" -o "${executable_dir}/${exec_name}" $flags
      ;;
  esac
done
