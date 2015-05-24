#!/bin/sh

executable_dir="executables"
flags="-std=c99 -pedantic -Werror -Wall -ggdb"

if [ ! -d "$executable_dir" ]; then
  mkdir "$executable_dir"
fi

if [ ! -z "$1" ]; then
  case "$1" in
    "--clean")
      echo "Cleaning out executables and recompiling.."
      rm -rf "$executable_dir"
      mkdir "$executable_dir"
    ;;
    *)
      echo `printf "No such command: %s" $1`
      exit 1
    ;;
  esac
fi

for file in ./lab/*; do
  case "$file" in
    *".c"*)
      exec_name=$(echo $file | cut -c 7- | rev | cut -c 3- | rev)
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
