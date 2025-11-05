#include "util/obj_loader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iostream>


namespace {
//triming skipping spaces    
std::string trim(const std::string& s){
    size_t a=0,b=s.size();
    while(a<b && std::isspace(static_cast<unsigned char>(s[a]))) ++a;
    while(b>a && std::isspace(static_cast<unsigned char>(s[b-1]))) --b;
    return s.substr(a,b-a);
}
//indexing to 0-based and changing string to int
int to_idx(const std::string& s) {
        if (s.empty()) return -1;
        return std::stoi(s) - 1;
}
// accepts: "v", "v//vn"
void parse_face_vertex(const std::string& tok, int& v, int& vn) {
    v = vn = -1;

    size_t p1 = tok.find('/');
    if (p1 == std::string::npos) {         // "v"
        v = std::stoi(tok) - 1;  // no first slash just get v
        return;
    }

    size_t p2 = tok.find('/', p1 + 1);     // may be npos

   

    // vertex is always before the first slash
    v = to_idx(tok.substr(0, p1));

    // vn logic (works for "v/vn" and "v//vn")
    std::string s1;
    if (p2 == std::string::npos) {
        s1 = tok.substr(p1 + 1);           // after first slash
        vn = to_idx(s1);
    } else {
        s1 = tok.substr(p2 + 1);           // after second slash
        vn = to_idx(s1);
    }
}


} // namespace

ObjData load_obj_file(const std::string& path) {
    std::ifstream in(path);
    if(!in) throw std::runtime_error("Failed to open OBJ: " + path);
    return load_obj_stream(in);
}
    
ObjData load_obj_stream(std::istream& istream) {
    ObjData out;
    std::string line;

    while(std::getline(istream, line)){
        line = trim(line);
        if(line.empty() || line[0]=='#') continue;
        std::istringstream iss(line);
        std::string tag; iss >> tag;
        
        
        

        if(tag == "v"){
            float x, y, z;
            iss >> x >> y >> z;
            out.V.push_back(Vec3{x, y, z});
        } else if(tag == "vn"){
            float x, y, z;
            iss >> x >> y >> z;
            out.VN.push_back(Vec3{x,y,z});
            
        } else if(tag == "f"){
            // only triangles
            std::vector<std::string> toks;
            for (std::string tok; iss >> tok; ) toks.push_back(tok);

            if (toks.size() != 3) {
                throw std::runtime_error("face must have exactly 3 vertices, found "
                         + std::to_string(toks.size()) + " (" + line + ")");
            }

            ObjData::Tri T{};
            parse_face_vertex(toks[0], T.v[0], T.vn[0]);
            std::cout << toks[0] << std::endl; 
            parse_face_vertex(toks[1], T.v[1], T.vn[1]);
            std::cout << toks[1] << std::endl; 
            parse_face_vertex(toks[2], T.v[2], T.vn[2]);
            std::cout << toks[2] << std::endl; 
            out.tris.push_back(T);
        }
        
    }
    return out;
}
