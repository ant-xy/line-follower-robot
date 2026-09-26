struct mapping {
    int func_ptr;
    int inv_func_ptr;
    int map;
}

struct mapping mappings[5] = {
    {"b","w","w","w","w"} // left
    {"b","b","w","w","w"} // left
    {"b","b","b","w","w"} // left
    {"b","b","b","b","w"} // left
    {"w","w","b","w","w"} // front
}
