#!/bin/bash

# Replace with your GitHub username and token
USERNAME="USERNAM_EMAILID"
TOKEN="PERSONAL_ACCESS_TOKEN"
DEST_DIR="."

mkdir -p "$DEST_DIR"
cd "$DEST_DIR" || exit

# Fetch list of repo clone URLs using GitHub API
curl -s -u $USERNAME:$TOKEN "https://api.github.com/user/repos?per_page=100" | \
  jq -r '.[].clone_url' | \
  while read -r repo; do
    git clone "$repo"
  done
