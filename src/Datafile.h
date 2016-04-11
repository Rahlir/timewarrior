////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2015 - 2016, Paul Beckingham, Federico Hernandez.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDED_DATAFILE
#define INCLUDED_DATAFILE

#include <Interval.h>
#include <FS.h>
#include <vector>
#include <string>

class Datafile
{
public:
  Datafile () = default;
  void initialize (const std::string&);
  std::string name () const;

  std::string lastLine ();
  std::vector <std::string> allLines ();

  void setExclusions (const std::vector <std::string>&);
  bool addInterval (const Interval&);
  bool deleteInterval (const Interval&);

  void commit ();

  std::string dump () const;

private:
  void load_lines ();

private:
  // File representing data.
  File                      _file             {};
  bool                      _dirty            {false};

  // Lines read from file, not parsed.
  std::vector <std::string> _lines            {};
  bool                      _lines_loaded     {false};

  // Exclusions fed from Database.
  std::vector <std::string> _exclusions       {};

  Datetime                  _day1             {0};
  Datetime                  _dayN             {0};
};

#endif
