#!/bin/bash

BIN="./file_reading"
TEST_DIR="./tmp_tests"
mkdir -p "$TEST_DIR"
# -p refers that don't complain if the directory already exists

# run test defines the function. local is a variable that only exists inside the function.
# $1, $2, are the positional parameters when calling the function.
run_test() {
    local name="$1"
    local content="$2"
    local target="$3"
    local replacer="$4"

    local file="$TEST_DIR/$name.txt"
    local replaced="$file.replace"

    # Prepare file
    # if the content was marked as EMPTY, it creates an empty file
    # if the content was a non-empty string, it writes content to that file (so if content was "", the file is not created even)
    if [ "$content" == "EMPTY" ]; then
        : > "$file"
    elif [ -n "$content" ]; then
        echo "$content" > "$file"
    fi

    # special edge-case for no permissions, we set the file permissions to read only
    # Permissions test
    [ "$name" == "no_permissions" ] && chmod 200 "$file"

    # Run program
    # runs the program with the arguments, 2>&1 redirects errors to stdout.
    # status stores the exit code
    output=$($BIN "$file" "$target" "$replacer" 2>&1)
    status=$?

    # only show program output if we encountered an error
    echo "==== Test: $name ===="
    echo "Target: '$target' | Replacer: '$replacer'"
    if [ $status -eq 1 ]; then
        echo "Program output:"
        echo "$output"
    fi

    # only shows files if the program didn't fail -eq refers to equal to. So if status is equal to 0
    if [ $status -eq 0 ]; then
        echo "--- Original ---"
        cat "$file"
        echo "--- Replaced ---"
        cat "$replaced"
    fi
    echo
    [ "$name" == "no_permissions" ] && chmod 600 "$file"
}

# --- Test Cases ---
run_test "file_missing" "" "hello" "you"
run_test "no_permissions" "hello" "hello" "you"
run_test "empty_file" "EMPTY" "hello" "you"
run_test "empty_target" "Hello you" "" "me"
run_test "empty_replacer" "Hello to you and me" " and me" ""
run_test "single_match" "Hello world" "world" "Universe"
run_test "multiple_matches" "world world world" "world" "Universe"
run_test "only_newlines" $'\n\nxox\n' "x" "y"
run_test "no_match" "Hello there" "world" "Universe"

echo "==== Test: invalid_args (no arguments) ===="
output=$($BIN 2>&1)
echo "Program output:"
echo "$output"
echo