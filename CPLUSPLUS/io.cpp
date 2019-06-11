#include <iostream>
#include <fstream>
using namespace std;

class WrongUsage
{
};
class FileOpenError
{
public:
  const char *filename;
  FileOpenError(const char *fn = NULL) : filename(fn) {}
};
class NoSuchFile : public FileOpenError
{
public:
  NoSuchFile(const char *fn = NULL) : FileOpenError(fn) {}
};

int main(int argc, char *argv[])
{
  ifstream infile;
  ofstream textfile, binaryfile;
  int rows, cols, me_y, me_x;

  try
  {
    if (argc != 2)
      throw WrongUsage();
    infile.open(argv[1]);
    if (!infile)
      throw NoSuchFile(argv[1]);
    infile >> rows >> cols;
    int map[rows][cols];
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        infile >> map[i][j];
    infile >> me_y >> me_x;
    infile.close();

    textfile.open("tfile");
    if (!textfile)
      throw FileOpenError("tfile");
    binaryfile.open("bfile", ostream::binary);
    if (!binaryfile)
      throw FileOpenError("bfile");

    textfile.setf(ios::hex, ios::basefield);
    textfile.setf(ios::showbase);
    textfile << rows << " " << cols << endl;
    binaryfile.write((char *)&rows, sizeof(int));
    binaryfile.write((char *)&cols, sizeof(int));

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        textfile << map[i][j] << " ";
      textfile << endl;
    }

    textfile << me_y << " " << me_x << endl;


    binaryfile.write((char *)map, sizeof(map));

    binaryfile.write((char *)&me_y, sizeof(int));
    binaryfile.write((char *)&me_x, sizeof(int));

    textfile.close();
    binaryfile.close();
  }
  catch (NoSuchFile e)
  {
    cerr << "file " << e.filename << " not found." << endl;
  }
  catch (FileOpenError e)
  {
    cerr << "file " << e.filename << " can not be opened." << endl;
  }
  catch (WrongUsage e)
  {
    cerr << "Usage : ./fileio filename" << endl;
  }
}