# -*- encoding: utf-8 -*-

require "json"
require 'logger'

logger = Logger.new(STDOUT)


task :install_clib_via_homebrew do
  if not File.exists?("/usr/local/bin/clib")
    sh "brew install clib"
  end
end

desc "Run a C project under Tsinghua_Online_Judge_problem directory."
task :run_a_C_project, [:project_name] => [:install_clib_via_homebrew] do |t, args|
  project_name = args[:project_name]
  project_dir  = "#{Dir.pwd}/Tsinghua_Online_Judge_problem/#{project_name}"
  config_json  = File.join(project_dir, "config.json")
  raise "Please provide a project name!" if project_name.nil?
  raise "#{project_dir} dont exists!" unless File.directory?(project_dir)
  raise "not exists #{config_json}" unless File.exists?(config_json)
  conf = JSON.parse(File.read(config_json))

  # 1. prepare clib
  packages = conf["clib_packages"]

  packages.each do |package|
    # package_path = File.join(Dir.pwd, "deps", package.split("/")[1])
    package_path = File.join(project_dir, package.split("/")[1])
    logger.info "check clib package exists? #{package_path}"
    if not File.directory?(package_path)
      sh "clib install #{package} -o #{project_dir}"
    end
  end

  # 2. compile project and run
  all_c_files = Dir[File.join(project_dir, "*"), File.join(project_dir, "*/*")].select do |f1|
    f1.match(/.c$/) && !File.directory?(f1)
  end
  main_executer = File.join(project_dir, "main.o")

  sh "clang #{all_c_files.join(' ')} -o #{main_executer}"
  run_result = `cat #{File.join(project_dir, "input.txt")} | #{main_executer}`

  logger.info "=== Run result"
  logger.info "\n#{run_result}"
  logger.info "=== Expected result"
  output_text = File.read(File.join(project_dir, 'output.txt'))
  logger.info "\n#{output_text}"
end

task :default do
  system "rake --tasks"
end
