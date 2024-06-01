#!/bin/bash

docker build -t unittest -f ./scripts/unittest.dockerfile .
docker run --rm unittest
