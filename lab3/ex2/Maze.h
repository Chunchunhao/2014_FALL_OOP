#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct point {
  int x=0, y=0;
};

struct Maze {
public:
  Maze() = default;
  Maze(const std::string &s): filename(s) {buildMap(s); findRoad();}

  std::vector<point>& find(void) {return path;};
  void findRoad(void);
  char getChar( int x, int y) const {return this->map[x][y];}
  void setChar( int x, int y) { this->map[x][y] = 'o';}
  unsigned getHeight() const {return this->hei;}
  unsigned getWidth() const {return this->wid;}
private:
  void buildMap(const std::string&);
  std::string filename = "";
  std::vector< std::vector<char> > map;
  std::vector<point> path;
  point start, end;
  unsigned hei, wid;
};

void Maze::buildMap(const std::string &fn){
  std::fstream fp;

  fp.open(fn);
  fp >> this->hei >> this->wid;
  //std::cout << "h: " << this->hei << "w: " << this->wid  << std::endl;

  std::string ll;
  std::getline(fp, ll);
  map.resize(this->hei);
  for( auto i=0; i<this->hei; i++){
    map[i].resize(this->wid);
    std::getline(fp, ll);
    //std::cout << "i: " << i << std::endl;
    //std::cout << "SS: " << ll << std::endl;
    for( auto j=0; j<this->wid; j++){
      //std::cout << "j: " << j << ", " << ll[j] << std::endl;
      map[i][j] = ll[j];
      if( this->map[i][j] ==  'S'){
        start.x = j;
        start.y = i;
      }
      else if( this->map[i][j] == 'F') {
        end.x = j;
        end.y = i;
      }
    }
  }
  //std::cout << "Begin : " << start.x << " , " << start.y << std::endl;
  //std::cout << "End : " << end.x << " , " << end.y << std::endl;
}

std::ostream &printLayout(std::ostream &os, const Maze &mm) {
  //std::cout << "hihi" << std::endl;;
  std::cout << mm.getHeight() << " " << mm.getWidth() << std::endl;
  for( int i=0; i < mm.getHeight(); i++){
    for( int j=0; j < mm.getWidth(); j++) {
      // os << "["<<i<<"]"<<"["<<j<<"]"<<mm.getChar(i, j);
      os << mm.getChar(i, j);
    }
    os << std::endl;
  }
  return os;
}

 
void Maze::findRoad(void) {
  int i = 0;
  point now;
  int right=0;
  //     0    1    2      3
  //point up, left, down, right;
  //std::vector<point> forward[4];
  point * forward = new point[4];
  // when the `right` is ... then the forward move is ...
  forward[0].x = -1;
  forward[0].y = 0;

  forward[1].x = 0;
  forward[1].y = 1;
  
  forward[2].x = 1;
  forward[2].y = 0;
  
  forward[3].x = 0;
  forward[3].y = -1;

  now.x = start.x ;
  now.y = start.y ;
  path.push_back(now);
  // First wall，沿著右邊走
  // std::cout << "Init x: " << now.x << ", y: " << now.y << std::endl; 
  if( now.x == 0 ) {
    right = 1;
  } 
  else if( now.x == wid ){
    right = 3;
  }
  else if( now.y == 0){
    right = 0;
  }
  else if( now.y == hei){
    right = 2;
  }
  else {
    right = 0;
    std::cout << "WTF11111" << std::endl;
  }

  do {

    // std::cout << "-----------: " << std::endl; 
    // std::cout << "now x: " << now.x << ", y: " << now.y << std::endl; 
    // std::cout << "end x: " << end.x << ", y: " << end.y << std::endl; 
    // std::cout << "right: " << right << std::endl; 
    // std::cout << "h: " << this->hei << ", w: " << this->wid  << std::endl;
    // std::cout << "now x++: " << now.x <<"+" << forward[right].x << ", y++: " << now.y <<"+"<< forward[right].y << std::endl; 
    // std::cout << "map: " << map[now.x+forward[right].x][now.y+forward[right].y] << std::endl; 
    
    if( now.x + forward[right].x < 0 || 
        now.x + forward[right].x > wid || 
        now.y + forward[right].y < 0 ||
        now.y + forward[right].y > hei ){
        right = ( (right + 1) % 4 );
    }
    else if( map[now.y+forward[right].y][now.x+forward[right].x] == '+' ){
        right = ( (right + 1) % 4 );       
    }
    else {
      now.x += forward[right].x;
      now.y += forward[right].y;
      if( right == 0)
        right = right +  4;
      
      right = right - 1;
      //std::cout << "-------- " << std::endl;
      //std::cout << "Move x: " << now.x << ", y: " << now.y << std::endl; 
      //std::cout << "Last x: " << path[path.size()-1].x << ", y: " << path[path.size()-1].y << std::endl; 
      if( path[path.size()-2].x == now.x && path[path.size()-2].y == now.y ){
        // std::cout << "pop" << std::endl;
        path.pop_back();
      }
      else {
        path.push_back(now);
      }
    }
  } while( !(now.x == end.x && now.y == end.y));

  // std::cout << "??????????" << std::endl;
  for(auto i=1; i< path.size()-1; i++){
    // std::cout << "(" << path[i].y << ", " << path[i].x<< ")" << std::endl;
    // std::cout << "map : " <<  map[ path[i].y ][ path[i].x ] << std::endl;
    map[ path[i].y ][ path[i].x ] = 'o';
  
  }
  return ;
}



std::ostream &printPath(std::ostream &os, std::vector<point> &p) {
  //os << "hi" ;
  for(auto i = 0; i < p.size(); i++){
    os << "(" << p[i].y << ", " << p[i].x<< ")" << std::endl;
  }
  return os;
}
