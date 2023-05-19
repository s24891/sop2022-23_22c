 #!/bin/bash
postal_code_regex='^[0-9]{2}-[0-9]{3}$'
if [[ ! "$1" =~ $postal_code_regex ]]; then
echo "Nieprawidłowy kod pocztowy."
else
echo "Prawidłowy kod pocztowy: $1"
fi
