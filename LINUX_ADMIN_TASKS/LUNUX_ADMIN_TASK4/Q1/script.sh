#!/bin/bash

USERNAME="KARIM"
GROUPNAME="ZIDAN"

# Check if the group exists, create if not
if grep -q "^${GROUPNAME}:" /etc/group; then
    echo "Group $GROUPNAME already exists."
else
    echo "Group $GROUPNAME does not exist. Creating group..."
    groupadd $GROUPNAME
    echo "Group $GROUPNAME created."
fi

# Check if the user exists, create if not
if grep -q "^${USERNAME}:" /etc/passwd; then
    echo "User $USERNAME already exists."
else
    echo "User $USERNAME does not exist. Creating user..."
    useradd -m -G $GROUPNAME $USERNAME
    echo "User $USERNAME created and added to group $GROUPNAME."
fi

# Display relevant information
echo "User information:"
id $USERNAME

echo "Group information:"
getent group $GROUPNAME

