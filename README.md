<h1 id="smellsfishy" align="center">SmellsFishy</h1>
<h3 id="smellsfishy" align="center">A SAST tool, to detect hard coded secrets</h3>

<p align="center">
    <img src="./doc/img/logo.png" alt="logo">
</p>

<p align="center">
    <a href="https://github.com/LazyKeru/SmellsFishy/tags">
        <img src="https://img.shields.io/github/v/tag/LazyKeru/SmellsFishy" alt="release">
    </a>
    <a href="https://github.com/semantic-release/semantic-release">
        <img src="https://img.shields.io/badge/semantic--release-angular-e10079?logo=semantic-release" alt="semantic-release: angular">
    </a>
    <a href="https://app.codiga.io/public/project/32693/SmellsFishy/dashboard">
        <img src="https://api.codiga.io/project/32693/status/svg" alt="codiga code grade">
    </a>
    <a href="https://opensource.org/licenses/MIT">
        <img src="https://img.shields.io/badge/License-MIT-green.svg" alt="MIT License">
    </a>
</p>
<p align="center">
    <a href="https://github.com/LazyKeru/SmellsFishy/actions/workflows/semantic_versioning.yml">
        <img src="https://img.shields.io/github/workflow/status/LazyKeru/SmellsFishy/Semantic-versionning?label=Versionning&logo=semantic-release" alt="semantic-versionning">
    </a>
    <a href="https://github.com/LazyKeru/SmellsFishy/actions/workflows/test_all.yml">
        <img src="https://img.shields.io/github/workflow/status/LazyKeru/SmellsFishy/Test-all?label=Test&logo=GitHub-Actions" alt="semantic-versionning">
    </a>
</p>

<p>A Source Code Analysis Tool to detect hard coded secrets. Written in C++, it uses Entropy, Regex and in the future machine learning algorithm for detection.</p>

<p>This is a project started in P6 
as part of our studies at <a href="https://imt-nord-europe.fr/">IMT Nord Europe</a></p>

<h2 id="how-to-use"> How to use ? </h2>

<p>To use our tool make sure your computer has <code>Make</code> or <code>Makefile</code>. You will then simply place yourself at the root of the project and enter : </p>

<pre><code>makefile main</code></pre>

<p>Then access the executable in the bin folder, and enjoy. The tool is still in beta</p>

<h3 id="how-to-use"> Arguments </h3>

<table>
    <thead> 
        <tr>
            <th style="text-align:left"> title </th>
            <th style="text-align:center"> arguments </th>
            <th style="text-align:center"> example </th>
            <th style="text-align:left"> description </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="text-align:left"> Help </td>
            <td style="text-align:center"><code>--help</code>/<code>-h</code></td>
            <td style="text-align:center"><code>main -h</code></td>
            <td style="text-align:left">Shows how to use the program</td>
        </tr>
        <tr>
            <td style="text-align:left"> Directory </td>
            <td style="text-align:center"><code>--dir</code>/<code>-d</code></td>
            <td style="text-align:center"><code>main -d "path" -r "path.json"</code></td>
            <td style="text-align:left">Path for the directory you want to analyze</td>
        </tr>
        <tr>
            <td style="text-align:left"> Rules </td>
            <td style="text-align:center"><code>--rules</code>/<code>-r</code></td>
            <td style="text-align:center"><code>main -d "path" -r "path.json"</code></td>
            <td style="text-align:left">Path to the rules json file we need to follow</td>
        </tr>
        <tr>
            <td style="text-align:left"> entropy </td>
            <td style="text-align:center"><code>--entropy</code>/<code>-e</code></td>
            <td style="text-align:center"><code>main -d "path" -r "path.json" -e</code></td>
            <td style="text-align:left">Activates the entropy rules, secrets out of bound from there rules entropy will be removed</td>
        </tr>
        <tr>
            <td style="text-align:left"> Log output </td>
            <td style="text-align:center"><code>--log</code>/<code>-l</code></td>
            <td style="text-align:center"><code>main -d "path" -r "path.json" -l "path.txt"</code></td>
            <td style="text-align:left">Path for the log output</td>
        </tr>
    </tbody>
</table>

<h2 id="commit-convention-"> Commit convention </h2>

<ul>
    <li>BREAKING CHANGE: </li>
    <li>build: Changes that affect the build system or external dependencies (example scopes: gulp, broccoli, npm)</li>
    <li>ci: Changes to our CI configuration files and scripts (examples: CircleCi, SauceLabs)</li>
    <li>docs: Documentation only changes</li>
    <li>feat: A new feature</li>
    <li>fix: A bug fix</li>
    <li>perf: A code change that improves performance</li>
    <li>refactor: A code change that neither fixes a bug nor adds a feature</li>
    <li>test: Adding missing tests or correcting existing tests</li>
</ul>
