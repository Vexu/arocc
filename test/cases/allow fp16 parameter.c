__fp16 foo(__fp16 x) {
    return 0;
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu -fnative-half-arguments-and-returns
*/
