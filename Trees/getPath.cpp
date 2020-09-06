void getPathUtil(Node* root, int key, vector<int>& path, bool& found) {
    if (!root) {
        return;
    }

    path.push_back(root->val);

    if (root->val == key) {
        found = true;
        return;
    }

    getPathUtil(root->left, key, path, found);

    if (!found)
        getPathUtil(root->right, key, path, found);

    if (!found) {
        path.pop_back();
    }

    return;
}

void getPathBT(Node* root, int key) {
    vector<int> path;
    bool found = false;

    getPathUtil(root, key, path, found);

    for (auto x : path) {
        cout << x << " ";
    }
    cout << endl;
}
