mkdir -p contrib
cd contrib

POCO_REV="poco-1.6.0"
POCO_FILE="$POCO_REV.tar.gz"
if [ -d "$POCO_REV" ]; then
  echo "Poco seems to be already installed."
else
  echo "Installing Poco..."
  curl "http://pocoproject.org/releases/$POCO_REV/$POCO_FILE" -o "$POCO_FILE"
  if [ -f "$POCO_FILE" ]; then
    tar -xvf "$POCO_FILE"
    rm -f "$POCO_FILE"
    cd "$POCO_REV"
    ./configure
    make -j4
  fi
  echo "Poco installed."
fi

GTEST_REV="gtest-1.7.0"
GTEST_FILE="$GTEST_REV.zip"
if [ -d "$GTEST_REV" ]; then
  echo "GTest seems to be already installed."
else
  echo "Installing GTest..."
  curl "http://googletest.googlecode.com/files/$GTEST_FILE" -o "$GTEST_FILE"
  if [ -f "$GTEST_FILE" ]; then
    unzip "$GTEST_FILE"
    rm -f "$GTEST_FILE"
    cd "$GTEST_REV"
    ./configure
    make
    sudo cp -a include/gtest /usr/local/include
    sudo cp -a lib/.libs/* /usr/local/lib
  fi
  echo "GTest installed."
fi

GMOCK_REV="gmock-1.7.0"
GMOCK_FILE="$GMOCK_REV.zip"
if [ -d "$GMOCK_REV" ]; then
  echo "GMock seems to be already installed."
else
  echo "Installing GMock..."
  curl "http://googlemock.googlecode.com/files/$GMOCK_FILE" -o "$GMOCK_FILE"
  if [ -f "$GMOCK_FILE" ]; then
    unzip "$GMOCK_FILE"
    rm -f "$GMOCK_FILE"
    cd "$GMOCK_REV"
    ./configure
    make
    sudo cp -a include/gmock /usr/local/include
    sudo cp -a lib/.libs/* /usr/local/lib
  fi
  echo "GMock installed."
fi

echo "Done."
