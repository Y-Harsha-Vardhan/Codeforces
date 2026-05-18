#!/bin/bash

# Contest name
NAME="$1"

# Paths
BASE=~/Desktop/CODE/Codeforces/Practice
TEMPLATE=~/Desktop/CODE/Codeforces/template.cpp

# Create contest folder
mkdir -p "$BASE/$NAME"

cd "$BASE/$NAME" || exit

# Create problem files
for file in A B C D
do
    cp "$TEMPLATE" "${file}.cpp"
done

# Create compile/run helper script
cat << 'EOF' > run
#!/bin/bash

FILE="$1"

g++ "${FILE}.cpp" -std=c++17 -O2 && ./a.out
EOF

chmod +x run

echo "Contest folder '$NAME' created."