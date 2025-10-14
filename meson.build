project('KSD', 'cpp', default_options: ['cpp_std=c++20'])

deps = [dependency('glfw3'), dependency('vulkan'), dependency('dl'), dependency('threads'), dependency('X11')]

inc = include_directories('.')

lve_sources= ['lve_window.cpp', 'lve_pipeline.cpp', 'lve_device.cpp', 'lve_swap_chain.cpp', 'lve_model.cpp', 'lve_renderer.cpp']
lve_lib = shared_library('lve', lve_sources, include_directories: inc, dependencies: deps)

program_sources = ['main.cpp', 'first_app.cpp', 'simple_render_system.cpp', 'keyboard_movement_controller.cpp']
exec = executable('tutorial', program_sources, include_directories: inc, dependencies: deps, link_with: lve_lib)
custom_target('compile_shaders', depends : exec, input : exec, output : 'fake', command : ['compile_shaders.sh'], build_by_default : true)