# Set your GitHub username and Personal Access Token (PAT)
$Username = "USERNAME_EMAILID"
$Token = "PERSONAL_ACCESS_TOKEN"

# GitHub API URL to get user's repositories (first 100)
$ApiUrl = "https://api.github.com/user/repos?per_page=100"

# Set headers with Authorization
$Headers = @{
    Authorization = "Basic " + [Convert]::ToBase64String([Text.Encoding]::ASCII.GetBytes("${Username}:${Token}"))
    "User-Agent" = "$Username"
}

# Get the list of repos
$response = Invoke-RestMethod -Uri $ApiUrl -Headers $Headers

# Loop through each repo and clone it
foreach ($repo in $response) {
    git clone $repo.clone_url
}
