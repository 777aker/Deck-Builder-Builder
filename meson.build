project('GTR', 'cpp', default_options: ['cpp_std=c++20'])

deps = [dependency('glfw3'), dependency('vulkan'), dependency('dl'), dependency('threads'), dependency('X11')]

lve_include = 'lve/'
lve_sources= ['lve/lve_window.cpp', 'lve/lve_pipeline.cpp', 'lve/lve_device.cpp', 'lve/lve_swap_chain.cpp', 'lve/lve_model.cpp', 'lve/lve_renderer.cpp', 'lve/lve_buffer.cpp', 'lve/lve_descriptors.cpp']
lve_lib = shared_library('lve', lve_sources, include_directories: lve_include, dependencies: deps)

inc = include_directories('.')
program_sources = ['main.cpp', 'gm.cpp', 'renderer.cpp', 'models.cpp']
exec = executable('tutorial', program_sources, include_directories: inc, dependencies: deps, link_with: lve_lib)
custom_target('compile_shaders', depends : exec, input : exec, output : 'fake', command : ['compile_shaders.sh'], build_by_default : true)
