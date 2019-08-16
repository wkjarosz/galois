/*
    NOTE: This file should be excluded from the Doxygen build
    
    License:  This file may be freely used and shared according to the original
    license.
    
    Reference:
    <ul><li><a href="http://lib.stat.cmu.edu/designs/">Statlib Designs</a></li>
    <li><a href="http://lib.stat.cmu.edu/designs/oa.c">Owen's Orthogonal Array
    Algorithms</a></li></ul>
    
    Original Header:
    <blockquote>
    These programs construct and manipulate orthogonal arrays.  They were
    prepared by
    
    - Art Owen
    - Department of Statistics
    - Sequoia Hall
    - Stanford CA 94305
    
    They may be freely used and shared.  This code comes
    with no warranty of any kind.  Use it at your own
    risk.
    
    I thank the Semiconductor Research Corporation and
    the National Science Foundation for supporting this
    work.
    </blockquote>
 */

/*  This code was computer generated */

/*  GF( p ^ 1 ) = GF( p ) */
const vector<int> xtnpt1 = {0};

/*  GF( 2 ^ 2 ) = GF( 4 ) */
const std::vector<int> xtn2t2 = {1,1};
/*  GF( 2 ^ 3 ) = GF( 8 ) */
const std::vector<int> xtn2t3 = {1,0,1};
/*  GF( 2 ^ 4 ) = GF( 16 ) */
const std::vector<int> xtn2t4 = {1,0,0,1};
/*  GF( 2 ^ 5 ) = GF( 32 ) */
const std::vector<int> xtn2t5 = {1,0,0,1,0};
/*  GF( 2 ^ 6 ) = GF( 64 ) */
const std::vector<int> xtn2t6 = {1,0,0,0,0,1};
/*  GF( 2 ^ 7 ) = GF( 128 ) */
const std::vector<int> xtn2t7 = {1,0,0,0,0,0,1};
/*  GF( 2 ^ 8 ) = GF( 256 ) */
const std::vector<int> xtn2t8 = {1,0,0,0,1,1,1,0};
/*  GF( 2 ^ 9 ) = GF( 512 ) */
const std::vector<int> xtn2t9 = {1,0,0,0,0,1,0,0,0};
/*  GF( 2 ^ 10 ) = GF( 1024 ) */
const std::vector<int> xtn2t10 = {1,0,0,0,0,0,0,1,0,0};
/*  GF( 2 ^ 11 ) = GF( 2048 ) */
const std::vector<int> xtn2t11 = {1,0,0,0,0,0,0,0,0,1,0};
/*  GF( 2 ^ 12 ) = GF( 4096 ) */
const std::vector<int> xtn2t12 = {1,0,0,0,1,0,0,0,0,0,1,1};
/*  GF( 2 ^ 13 ) = GF( 8192 ) */
const std::vector<int> xtn2t13 = {1,0,0,0,0,0,0,0,1,0,0,1,1};
/*  GF( 2 ^ 14 ) = GF( 16384 ) */
const std::vector<int> xtn2t14 = {1,0,1,0,0,0,0,0,0,0,0,0,1,1};
/*  GF( 2 ^ 15 ) = GF( 32768 ) */
const std::vector<int> xtn2t15 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
/*  GF( 2 ^ 16 ) = GF( 65536 ) */
const std::vector<int> xtn2t16 = {1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1};
/*  GF( 2 ^ 17 ) = GF( 131072 ) */
const std::vector<int> xtn2t17 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
/*  GF( 2 ^ 18 ) = GF( 262144 ) */
const std::vector<int> xtn2t18 = {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0};
/*  GF( 2 ^ 19 ) = GF( 524288 ) */
const std::vector<int> xtn2t19 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1};
/*  GF( 2 ^ 20 ) = GF( 1048576 ) */
const std::vector<int> xtn2t20 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
/*  GF( 2 ^ 21 ) = GF( 2097152 ) */
const std::vector<int> xtn2t21 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
/*  GF( 2 ^ 22 ) = GF( 4194304 ) */
const std::vector<int> xtn2t22 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
/*  GF( 2 ^ 23 ) = GF( 8388608 ) */
const std::vector<int> xtn2t23 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0};
/*  GF( 2 ^ 24 ) = GF( 16777216 ) */
const std::vector<int> xtn2t24 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1};
/*  GF( 2 ^ 25 ) = GF( 33554432 ) */
const std::vector<int> xtn2t25 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
/*  GF( 2 ^ 26 ) = GF( 67108864 ) */
const std::vector<int> xtn2t26 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1};
/*  GF( 2 ^ 27 ) = GF( 134217728 ) */
const std::vector<int> xtn2t27 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1};
/*  GF( 2 ^ 28 ) = GF( 268435456 ) */
const std::vector<int> xtn2t28 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
/*  GF( 2 ^ 29 ) = GF( 536870912 ) */
const std::vector<int> xtn2t29 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};

/*  GF( 3 ^ 2 ) = GF( 9 ) */
const std::vector<int> xtn3t2 = {1,2};
/*  GF( 3 ^ 3 ) = GF( 27 ) */
const std::vector<int> xtn3t3 = {2,0,1};
/*  GF( 3 ^ 4 ) = GF( 81 ) */
const std::vector<int> xtn3t4 = {1,0,0,2};
/*  GF( 3 ^ 5 ) = GF( 243 ) */
const std::vector<int> xtn3t5 = {2,0,2,0,2};
/*  GF( 3 ^ 6 ) = GF( 729 ) */
const std::vector<int> xtn3t6 = {1,0,0,0,0,2};
/*  GF( 3 ^ 7 ) = GF( 2187 ) */
const std::vector<int> xtn3t7 = {2,0,0,0,2,0,2};
/*  GF( 3 ^ 8 ) = GF( 6561 ) */
const std::vector<int> xtn3t8 = {1,0,0,0,0,2,0,0};
/*  GF( 3 ^ 9 ) = GF( 19683 ) */
const std::vector<int> xtn3t9 = {2,0,0,0,0,2,0,2,0};
/*  GF( 3 ^ 10 ) = GF( 59049 ) */
const std::vector<int> xtn3t10 = {1,0,0,0,0,0,0,2,0,2};
/*  GF( 3 ^ 11 ) = GF( 177147 ) */
const std::vector<int> xtn3t11 = {2,0,0,0,2,0,0,0,0,0,2};
/*  GF( 3 ^ 12 ) = GF( 531441 ) */
const std::vector<int> xtn3t12 = {1,0,0,0,0,0,0,2,0,0,0,2};
/*  GF( 3 ^ 13 ) = GF( 1594323 ) */
const std::vector<int> xtn3t13 = {2,0,0,0,0,0,2,0,0,0,0,0,2};
/*  GF( 3 ^ 14 ) = GF( 4782969 ) */
const std::vector<int> xtn3t14 = {1,0,0,0,0,0,0,0,0,0,0,0,0,2};
/*  GF( 3 ^ 15 ) = GF( 14348907 ) */
const std::vector<int> xtn3t15 = {2,0,0,0,2,0,0,0,0,0,0,0,0,0,2};
/*  GF( 3 ^ 16 ) = GF( 43046721 ) */
const std::vector<int> xtn3t16 = {1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0};
/*  GF( 3 ^ 17 ) = GF( 129140163 ) */
const std::vector<int> xtn3t17 = {2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,2};
/*  GF( 3 ^ 18 ) = GF( 387420489 ) */
const std::vector<int> xtn3t18 = {1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2};

/*  GF( 5 ^ 2 ) = GF( 25 ) */
const std::vector<int> xtn5t2 = {3,4};
/*  GF( 5 ^ 3 ) = GF( 125 ) */
const std::vector<int> xtn5t3 = {3,0,4};
/*  GF( 5 ^ 4 ) = GF( 625 ) */
const std::vector<int> xtn5t4 = {2,4,0,4};
/*  GF( 5 ^ 5 ) = GF( 3125 ) */
const std::vector<int> xtn5t5 = {3,0,4,0,0};
/*  GF( 5 ^ 6 ) = GF( 15625 ) */
const std::vector<int> xtn5t6 = {3,0,0,0,0,4};
/*  GF( 5 ^ 7 ) = GF( 78125 ) */
const std::vector<int> xtn5t7 = {3,0,0,0,0,0,4};
/*  GF( 5 ^ 8 ) = GF( 390625 ) */
const std::vector<int> xtn5t8 = {2,0,0,4,0,4,0,0};
/*  GF( 5 ^ 9 ) = GF( 1953125 ) */
const std::vector<int> xtn5t9 = {2,0,0,0,0,0,4,4,0};
/*  GF( 5 ^ 10 ) = GF( 9765625 ) */
const std::vector<int> xtn5t10 = {2,0,0,0,0,0,0,4,0,4};
/*  GF( 5 ^ 11 ) = GF( 48828125 ) */
const std::vector<int> xtn5t11 = {3,0,0,0,0,0,0,0,0,0,4};
/*  GF( 5 ^ 12 ) = GF( 244140625 ) */
const std::vector<int> xtn5t12 = {2,0,0,0,4,0,0,4,0,0,0,0};

/*  GF( 7 ^ 2 ) = GF( 49 ) */
const std::vector<int> xtn7t2 = {4,6};
/*  GF( 7 ^ 3 ) = GF( 343 ) */
const std::vector<int> xtn7t3 = {5,6,6};
/*  GF( 7 ^ 4 ) = GF( 2401 ) */
const std::vector<int> xtn7t4 = {4,0,6,6};
/*  GF( 7 ^ 5 ) = GF( 16807 ) */
const std::vector<int> xtn7t5 = {3,0,0,0,6};
/*  GF( 7 ^ 6 ) = GF( 117649 ) */
const std::vector<int> xtn7t6 = {4,0,0,0,6,6};
/*  GF( 7 ^ 7 ) = GF( 823543 ) */
const std::vector<int> xtn7t7 = {3,0,0,0,0,6,0};
/*  GF( 7 ^ 8 ) = GF( 5764801 ) */
const std::vector<int> xtn7t8 = {4,0,0,0,0,0,0,6};
/*  GF( 7 ^ 9 ) = GF( 40353607 ) */
const std::vector<int> xtn7t9 = {5,0,0,6,0,0,0,0,6};
/*  GF( 7 ^ 10 ) = GF( 282475249 ) */
const std::vector<int> xtn7t10 = {4,0,0,0,0,0,0,0,6,6};

/*  GF( 11 ^ 2 ) = GF( 121 ) */
const std::vector<int> xtn11t2 = {4,10};
/*  GF( 11 ^ 3 ) = GF( 1331 ) */
const std::vector<int> xtn11t3 = {6,0,10};
/*  GF( 11 ^ 4 ) = GF( 14641 ) */
const std::vector<int> xtn11t4 = {9,10,0,0};
/*  GF( 11 ^ 5 ) = GF( 161051 ) */
const std::vector<int> xtn11t5 = {2,0,10,10,0};
/*  GF( 11 ^ 6 ) = GF( 1771561 ) */
const std::vector<int> xtn11t6 = {4,10,0,0,0,10};
/*  GF( 11 ^ 7 ) = GF( 19487171 ) */
const std::vector<int> xtn11t7 = {6,0,0,0,0,0,10};
/*  GF( 11 ^ 8 ) = GF( 214358881 ) */
const std::vector<int> xtn11t8 = {9,10,0,0,10,0,0,0};

/*  GF( 13 ^ 2 ) = GF( 169 ) */
const std::vector<int> xtn13t2 = {11,12};
/*  GF( 13 ^ 3 ) = GF( 2197 ) */
const std::vector<int> xtn13t3 = {6,0,12};
/*  GF( 13 ^ 4 ) = GF( 28561 ) */
const std::vector<int> xtn13t4 = {11,12,0,12};
/*  GF( 13 ^ 5 ) = GF( 371293 ) */
const std::vector<int> xtn13t5 = {2,12,0,12,0};
/*  GF( 13 ^ 6 ) = GF( 4826809 ) */
const std::vector<int> xtn13t6 = {7,0,0,12,0,12};
/*  GF( 13 ^ 7 ) = GF( 62748517 ) */
const std::vector<int> xtn13t7 = {7,0,0,0,12,0,0};
/*  GF( 13 ^ 8 ) = GF( 815730721 ) */
const std::vector<int> xtn13t8 = {11,0,0,0,0,12,12,0};

/*  GF( 17 ^ 2 ) = GF( 289 ) */
const std::vector<int> xtn17t2 = {14,16};
/*  GF( 17 ^ 3 ) = GF( 4913 ) */
const std::vector<int> xtn17t3 = {3,16,0};
/*  GF( 17 ^ 4 ) = GF( 83521 ) */
const std::vector<int> xtn17t4 = {12,0,0,16};
/*  GF( 17 ^ 5 ) = GF( 1419857 ) */
const std::vector<int> xtn17t5 = {3,0,0,0,16};
/*  GF( 17 ^ 6 ) = GF( 24137569 ) */
const std::vector<int> xtn17t6 = {14,0,0,0,0,16};
/*  GF( 17 ^ 7 ) = GF( 410338673 ) */
const std::vector<int> xtn17t7 = {3,0,0,16,0,0,0};

/*  GF( 19 ^ 2 ) = GF( 361 ) */
const std::vector<int> xtn19t2 = {17,18};
/*  GF( 19 ^ 3 ) = GF( 6859 ) */
const std::vector<int> xtn19t3 = {3,0,18};
/*  GF( 19 ^ 4 ) = GF( 130321 ) */
const std::vector<int> xtn19t4 = {17,0,0,18};
/*  GF( 19 ^ 5 ) = GF( 2476099 ) */
const std::vector<int> xtn19t5 = {3,18,0,0,0};
/*  GF( 19 ^ 6 ) = GF( 47045881 ) */
const std::vector<int> xtn19t6 = {16,18,0,0,0,0};
/*  GF( 19 ^ 7 ) = GF( 893871739 ) */
const std::vector<int> xtn19t7 = {10,0,0,0,0,18,0};

/*  GF( 23 ^ 2 ) = GF( 529 ) */
const std::vector<int> xtn23t2 = {16,22};
/*  GF( 23 ^ 3 ) = GF( 12167 ) */
const std::vector<int> xtn23t3 = {7,0,22};
/*  GF( 23 ^ 4 ) = GF( 279841 ) */
const std::vector<int> xtn23t4 = {12,22,0,0};
/*  GF( 23 ^ 5 ) = GF( 6436343 ) */
const std::vector<int> xtn23t5 = {5,0,0,0,22};
/*  GF( 23 ^ 6 ) = GF( 148035889 ) */
const std::vector<int> xtn23t6 = {16,0,0,0,0,22};

/*  GF( 29 ^ 2 ) = GF( 841 ) */
const std::vector<int> xtn29t2 = {26,28};
/*  GF( 29 ^ 3 ) = GF( 24389 ) */
const std::vector<int> xtn29t3 = {11,28,0};
/*  GF( 29 ^ 4 ) = GF( 707281 ) */
const std::vector<int> xtn29t4 = {27,0,0,28};
/*  GF( 29 ^ 5 ) = GF( 20511149 ) */
const std::vector<int> xtn29t5 = {3,0,0,28,0};
/*  GF( 29 ^ 6 ) = GF( 594823321 ) */
const std::vector<int> xtn29t6 = {26,28,0,0,0,0};

/*  GF( 31 ^ 2 ) = GF( 961 ) */
const std::vector<int> xtn31t2 = {19,30};
/*  GF( 31 ^ 3 ) = GF( 29791 ) */
const std::vector<int> xtn31t3 = {3,30,0};
/*  GF( 31 ^ 4 ) = GF( 923521 ) */
const std::vector<int> xtn31t4 = {18,0,0,30};
/*  GF( 31 ^ 5 ) = GF( 28629151 ) */
const std::vector<int> xtn31t5 = {11,0,0,30,0};
/*  GF( 31 ^ 6 ) = GF( 887503681 ) */
const std::vector<int> xtn31t6 = {19,0,0,0,0,30};

/*  GF( 37 ^ 2 ) = GF( 1369 ) */
const std::vector<int> xtn37t2 = {32,36};
/*  GF( 37 ^ 3 ) = GF( 50653 ) */
const std::vector<int> xtn37t3 = {13,0,36};
/*  GF( 37 ^ 4 ) = GF( 1874161 ) */
const std::vector<int> xtn37t4 = {35,36,0,0};
/*  GF( 37 ^ 5 ) = GF( 69343957 ) */
const std::vector<int> xtn37t5 = {5,36,0,0,0};

/*  GF( 41 ^ 2 ) = GF( 1681 ) */
const std::vector<int> xtn41t2 = {29,40};
/*  GF( 41 ^ 3 ) = GF( 68921 ) */
const std::vector<int> xtn41t3 = {6,40,0};
/*  GF( 41 ^ 4 ) = GF( 2825761 ) */
const std::vector<int> xtn41t4 = {24,40,0,0};
/*  GF( 41 ^ 5 ) = GF( 115856201 ) */
const std::vector<int> xtn41t5 = {6,0,0,0,40};

/*  GF( 43 ^ 2 ) = GF( 1849 ) */
const std::vector<int> xtn43t2 = {40,42};
/*  GF( 43 ^ 3 ) = GF( 79507 ) */
const std::vector<int> xtn43t3 = {3,42,0};
/*  GF( 43 ^ 4 ) = GF( 3418801 ) */
const std::vector<int> xtn43t4 = {23,42,0,0};
/*  GF( 43 ^ 5 ) = GF( 147008443 ) */
const std::vector<int> xtn43t5 = {3,0,0,0,42};

/*  GF( 47 ^ 2 ) = GF( 2209 ) */
const std::vector<int> xtn47t2 = {34,46};
/*  GF( 47 ^ 3 ) = GF( 103823 ) */
const std::vector<int> xtn47t3 = {5,0,46};
/*  GF( 47 ^ 4 ) = GF( 4879681 ) */
const std::vector<int> xtn47t4 = {42,0,0,46};
/*  GF( 47 ^ 5 ) = GF( 229345007 ) */
const std::vector<int> xtn47t5 = {5,46,0,0,0};
