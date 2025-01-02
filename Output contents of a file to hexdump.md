To output the contents of a file in a human-readable hexadecimal format, you can use the cat command to read the file and pipe it to a hex-dumping utility like xxd or hexdump. Here are examples:

Using xxd:

cat <file_name> | xxd

Using hexdump:

cat <file_name> | hexdump -C

Explanation:
	•	cat <file_name>: Outputs the contents of the file.
	•	|: Pipes the output of the cat command to the next command.
	•	xxd: Displays the content in a hex dump with both hexadecimal and ASCII representations.
	•	hexdump -C: Produces a canonical hex dump, showing hexadecimal and ASCII side-by-side.

Example:

If you have a file named example.txt:

cat example.txt | xxd

or

cat example.txt | hexdump -C

Note:

You can directly use xxd or hexdump without cat, like so:

xxd <file_name>
hexdump -C <file_name>