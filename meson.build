project('KSD', 'cpp', default_options: ['cpp_std=c++20'])

deps = [dependency('glfw3'), dependency('vulkan'), dependency('dl'), dependency('threads'), dependency('X11')]

lve_include = 'lve/'
lve_sources= ['lve/lve_window.cpp', 'lve/lve_pipeline.cpp', 'lve/lve_device.cpp', 'lve/lve_swap_chain.cpp', 'lve/lve_model.cpp', 'lve/lve_renderer.cpp']
lve_lib = shared_library('lve', lve_sources, include_directories: lve_include, dependencies: deps)

inc = include_directories('.')
program_sources = ['main.cpp', 'first_app.cpp', 'simple_render_system.cpp', 'keyboard_movement_controller.cpp']
exec = executable('tutorial', program_sources, include_directories: inc, dependencies: deps, link_with: lve_lib)
custom_target('compile_shaders', depends : exec, input : exec, output : 'fake', command : ['compile_shaders.sh'], build_by_default : true)