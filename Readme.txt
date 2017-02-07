compiling error msg: 

Application ELF       : output/005_leonrt_test.elf
leon_rt/leonRTApp.rtlib: In function `http_get':
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:52: undefined reference to `lrt_socket'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:53: undefined reference to `lrt_server_addr'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:58: undefined reference to `lrt_connect'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:58: undefined reference to `lrt_server_addr'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:59: undefined reference to `lrt_server_addr'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:59: undefined reference to `lrt_inet_ntoa'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:63: undefined reference to `lrt_inet_ntoa'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:63: undefined reference to `lrt_http_request'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:65: undefined reference to `lrt_http_request'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:66: undefined reference to `lrt_http_headers'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:66: undefined reference to `lrt_http_headers'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:68: undefined reference to `lrt_http_request'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:69: undefined reference to `lrt_send'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test/leon_rt/main.c:84: undefined reference to `lrt_recv'
/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/tools/00.50.79.2/linux64/sparc-myriad-elf-4.8.2/bin/sparc-myriad-elf-ld: link errors found, deleting executable `./output/005_leonrt_test.elf'
../../../common/generic.mk:99: recipe for target 'output/005_leonrt_test.elf' failed
make[2]: *** [output/005_leonrt_test.elf] Error 1
rm leon_rt/leonRTApp.rtlibtemp
make[2]: Leaving directory '/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test'
make[2]: Entering directory '/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test'
Removing ELF file './output/005_leonrt_test.elf'
exit 1 # take care to fail the overall build as this target is called upon failure
../../../common/generic.mk:91: recipe for target 'delete_elf' failed
make[2]: *** [delete_elf] Error 1
make[2]: Leaving directory '/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test'
../../../common/generic.mk:74: recipe for target 'all' failed
make[1]: *** [all] Error 2
make[1]: Leaving directory '/home/fangli/PHANTOM/phantom_mf/movidius/mdk_release_16.10.9_general_purpose/mdk/examples/HowTo/005_leonrt_test'
../../../common/generic.mk:30: recipe for target 'all' failed
make: *** [all] Error 2
